//
// Created by DELL on 22/03/2021.
//

#include "Position.h"

Position::Position(int a,int b):x(a),y(b){}             // constructeur de classe
bool Position::CaseValidation(GameSpace ech , int test)     // si test =1 il verifie si la nouvelle position est dans l'espace jeu ou non , et si test = 0 il verifie si la nouvelle position est vide ou non.
{
    if(test==1)
    {
        // verification si la position est dans l'espace jeu
        return(1<=x && x<=ech.getsize() && 1<=y && y<=ech.getsize());

    }
    if(test==0)
    {
        //verification si la position est vide
        return(ech.GetCase(x,y)==IsEmpty) ;
    }
}
Position Position::GetNeighborPos(int way)    //cette fonction prendre la direction de mouvement et retourne la position voisine selon cette direction
{
    Position neighbor ; //  constructeur deja defini par défaut
    neighbor.x=x+WayToMove[way][0] ;
    neighbor.y=y+WayToMove[way][1] ;
    return(neighbor) ;
}
bool Position::NeighborCaseValidation(const GameSpace& ech,int way)      //validation si la case voisine est vide ou detruite ou au bord (il utilise la methode GetNeighborPos)
 // ce type de passage par parametre indique que cette methode ne fait pas de changment sur l'echiquier
{
    Position neighbor=GetNeighborPos(way) ;
    return(neighbor.CaseValidation(ech,1)&&neighbor.CaseValidation(ech,0)) ;
}
Position Position::GetNewMovmentOfCase(const GameSpace& ech)        //cette fonction demande au joueur la direction et retourne la nouvelle position
{
    int way;
    bool test=false ;
    do
    {
        cout<<"entrez la direction qui vous voulez faire "<<endl ;
        cin>>way ;
    }while(!(0<=way&&way<10&&NeighborCaseValidation(ech,way))) ;
    return(GetNeighborPos(way)) ;
}
bool Position::BlockedCase(const GameSpace& ech)  //tester si les joueurs sont bloques ou non
{
    for(int i=1 ;i<10;++i)
    {
        if(i!=5)
        {

            if(NeighborCaseValidation(ech,i))
            {
                return(false);
                //s'il y a au moins une case valide alors le joueur n'est pas bloqué

            }

        }

    }
    return(true);//tous les joueurs sont bloqués

}
int Position::NbrOfFreeCases(const GameSpace& ech)      //calculer le nombre des cases vides qui entoure une position
{
    int NbrOfFree=0 ;
    for(int i=1 ; i<10;++i)
    {
        if(i!=5&&NeighborCaseValidation(ech,i))
        {
            NbrOfFree+=1 ;
        }
    }
    return(NbrOfFree);
}
Position Position::FindOptimalNeighborCase(const GameSpace& ech)        //chercher la case optimale pour faire le meilleur mouvement
{
    int Nbmax=0; // nombre maximal des cases libres autour d'une case
    int BestWay=-1; // la bonne direction à suivre
    Position way1;
    for(int i=1 ;i<10;++i )
    {
        if(i!=5)
        {
            way1=GetNeighborPos(i);
            if(/*1<=i&&i<10&&*/NeighborCaseValidation(ech,i))
            {
                int nbFree=way1.NbrOfFreeCases(ech);
                if(nbFree>=Nbmax)
                {
                    Nbmax=nbFree;                  //c.a.d il va chercher la position dont laquelle ele possede le plus grand nombre des cases vides
                    BestWay=i ;
                }
            }
        }
    }
    Position wayis(0,0);
    if(BestWay==-1)             //c.a.d il reste dans sa position
    {
        wayis.x=x;
        wayis.y=y;
    }
    else wayis=GetNeighborPos(BestWay) ;
    return(wayis) ;

}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int x) {
    Position::x = x;
}

void Position::setY(int y) {
    Position::y = y;
}
int Position::ListOfPlayerLegalMoves(const GameSpace& ech)     //retourner le nombre des cases vides accessibles par le joueur
{
    vector<Position> t ;
    for(int i=1;i<=9;i++)
    {
        if(NeighborCaseValidation(ech,i))
            t.push_back(GetNeighborPos(i)) ;

    }
    return(t.size()) ;
}
vector<Position> Position::ListOfPlayerLegalMoves1(const GameSpace & ech)   //retourner un tableau qui renferme les positions des cases vides accessiblex
{
    vector<Position> t ;
    for(int i=1;i<=9;i++)
    {
        if(NeighborCaseValidation(ech,i))
            t.push_back(GetNeighborPos(i)) ;

    }
    return(t) ;
}
