//
// Created by DELL on 22/03/2021.
//

#ifndef ISOLAGAME_ISOLAGAME_H
#define ISOLAGAME_ISOLAGAME_H
#include "GameSpace.h"
#include "Position.h"
#include <cstdlib>
#include <vector>
#include <limits>
#include <cmath>
//nombre max des joueurs
const int MaxPlayers=10 ;
//le profondeur max de recherche pour mini_max
const int max_depth=30 ;

class IsolaGame {
    //*********attributs de classe*******
    GameSpace GS; // l'espace jeu
    Position Plys[MaxPlayers]; //cet attribut modelise la position actuelle de chaque joueur dans le jeu
    int NbPlayers ; // nombre de joueurs totals
    int NbIAmachines ; // nombre de joueurs machines
    int ActivePlayer ; // numero de joueurs actifs
    //**************methodes de classe****************
public:
    int getActivePlayer() const;

    IsolaGame(int,int,int nbmachine=0 ) ;//constructeur de la classe IsolaGame (dimension,nombre des joueurs total,nombre des joueurs machine)
    void DisplayGame() ; // afficher et initialiser le jeu
    void GivePlayerTurn() ; // passer la main a un autre joueur c.a.d incrementer le activeplayer
    //***********les mouvements des joueurs dans le jeu*****************
    static void SwitchCase(GameSpace&,const Position&,const Position&) ; //SwitchCase est une methode a pour role de permuter les cases d'un espace jeu
    void MovePlayerInGame() ; // MovePlayerInGame c'est une methode qui s'applique sur une instance de classe IsolaGame permet de changer la position d'un joueur
    //************pour la destruction d'une case*****************
    Position AskForCaseToDestroy() ; //accès a la case a detruire
    void DestroyCase(GameSpace&,const Position&) ;//detruire une case
    void DestroyCaseInGame() ; //detruire une case dans le jeu (cette methode utilise DestroyCase et AskForCaseToDestroy )
    //*************tester si un jeu est determinèe*****************
    bool EndGame() ; // tester la fin de jeux


    //*************le mouvement du IAplayer dans le jeu*******************
    void  MovePlayerInGameIA() ; //si le joueur est la machine donc il va chercher la position optimale , sinon il va demander à l'utilisateur de jouer
    Position FindCaseToDestroyIA() ;
    // IADestroyCaseInGame: il va detruire une case dans le jeu et afficher la nouvelle partie
    // donner la main a un joueur normal pour jouer
    void IADestroyCaseInGame() ;//detruire la case retourner par FindCaseToDestroyIA (car il utilise cette methode)

    //****************Minimax Bot*****************************
    static GameSpace FutureGameSpace(GameSpace,int,Position) ; // il va donner la nouvelle GameSpace après le coup du dernier joueur
    int NbrGetEmptyCases() ; // donner le nombre total des cases vides du GameSpace
    float GetHeuristicOfGameState(Position,Position,GameSpace) ; // calculer l'Heuristic score d'un etat de jeu particulier
    float maxval(GameSpace,Position,Position,int,float,float); // donner l'Heuristec score maximal de la profondeur actuelle dans l'arbre de jeu
    float minval(GameSpace,Position,Position,int,float ,float ) ; // donner l'Heuristec score minimal dde la profondeur actuelle dans l'arbre de jeu
    Position MiniMaxWithAlphaBetaPruning(GameSpace,Position,Position,int,float,float) ; //l'algorithme de minimax ordinaire mais avec une autre methode appeleè alpha beta pruning (il accelère la recherche )
    //il nous permet de faire une recherche plus vite dans l'arbre que mini_max
    //la methode MiniMaxWithAlphaBetaPruning nous retournè la position optimal
    void  MovePlayerInGameIAWithMiniMax() ;//deplacer le joueur machine dans l'espace jeu vers la position optimale retourner par MiniMaxWithAlphaBetaPruning
    void IADestroyCaseInGameMiniMax();

};


#endif //ISOLAGAME_ISOLAGAME_H
