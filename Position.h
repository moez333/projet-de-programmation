//
// Created by DELL on 22/03/2021.
//

#ifndef ISOLAGAME_POSITION_H
#define ISOLAGAME_POSITION_H
//Dans la classe Position une case est representèe par ses coordonnees (ligne , colonne )
#include "GameSpace.h"
#include <iostream>
#include <vector>
using namespace std ;
// si la case est à l'interieur elle admet 8 voisins sinon elle admet 3

//matrice de taille 10*2 chaque ligne représente une direction
//remplissage automatique({ordonnee,abscisse} ;
const int WayToMove[10][2]={
        {0,0}/* 0 fixed */ ,
        {1,-1} /*1 sw*/,
        {1,0} /*2 sud*/ ,
        {1,1} /*3 se*/ ,
        {0,-1} /*4 Ouest*/ ,
        {0,0} /*5 fixed dont move*/,
        {0,1} /*6 est*/ ,
        {-1,-1} /*7 nw*/ ,
        {-1,0} /*8 North*/ ,
        {-1,1} /*9 ne*/}  ;

class Position {
    //*****************attributs et methodes de classe*****************
    int x ;  //abscisse
    int y ;  //ordonnee
public :
     void setX(int x);  //setteur
     int getX() const;    //getteur
     void setY(int y);    //setteur
     int getY() const;    //getteur

    Position(int a=0 ,int b=0) ; // constructeur de la classe
    bool CaseValidation(GameSpace,int) ; // si int =1 il verifie si la nouvelle position est dans l'espace jeu ou non , et si int = 0 il verifie si la nouvelle position est vide ou non.
    Position GetNeighborPos(int) ; //cette fonction prendre la direction du mouvement et retourne la position voisine selon cette direction
    bool NeighborCaseValidation(const GameSpace&,int) ; //validation si la case voisin est vide ou detruit ou un bord (il utilise la methode GetNeighborPos)
    Position GetNewMovmentOfCase(const GameSpace&) ; //cette fonction demande au joueur la direction et retourne la nouvelle position
    //*******methode de fin de jeu************
    bool BlockedCase(const GameSpace&) ;  //tester si les joueurs sont bloquees ou non
    ///cote IA
    //**************(1)les methodes necessaire pour le PVE********************
    int NbrOfFreeCases(const GameSpace& ech) ;  //calculer le nombre des cases vides qui entourent une position
    Position FindOptimalNeighborCase(const GameSpace&) ; //chercher la case optimale pour faire le meilleur coup
    //*********(2) les methodes necessaires pour l'algorithme de minimax **************
    int ListOfPlayerLegalMoves(const GameSpace&) ;//retourner le nombre des cases vides accessibles par le joueur
    vector<Position> ListOfPlayerLegalMoves1(const GameSpace&) ;//retourner un tableau qui renferme les position des cases vides accessibles
};


#endif //ISOLAGAME_POSITION_H
