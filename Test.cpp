#include <iostream>
using  namespace  std ;
#include <ctime>
#include <stdlib.h>
#include "IsolaGame.cpp"
#include "GameSpace.cpp"
#include "Position.cpp"
//put all 2gather for PVP
void isolaGamepvp(int Size,int nbp)
{
    cout<< "PVP Game" << endl ;
    IsolaGame Game(Size,nbp) ;
    while(!(Game.EndGame()))
    {
        //display of game
        Game.DisplayGame() ;
        //move of active player
        Game.MovePlayerInGame() ;
        system("CLS") ;
        Game.DisplayGame() ;
        //destruction of case
        Game.DestroyCaseInGame();
        system("CLS") ;
        Game.DisplayGame();
        //pass to next player
        Game.GivePlayerTurn();
        system("CLS") ;
    }
    // loser hh
    cout<<"le perdant est : "<<Game.getActivePlayer()<<endl ;
    system("pause") ;

}
//put all 2gater for PVE
void isolaGamepve(int Size,int nbp,int nbm)
{
    cout<<" PVE Game "<<endl ;
    IsolaGame Game(Size,nbp,nbm) ;
    while(!(Game.EndGame()))
    {
        //display of game
        Game.DisplayGame();
        //move of active player
        Game.MovePlayerInGameIA();
        system("CLS") ;
        Game.DisplayGame();
        //destruction of case
        Game.IADestroyCaseInGame();
        system("CLS") ;
        Game.DisplayGame();
        //pass to next player
        Game.GivePlayerTurn();
        system("CLS") ;
    }
    cout<<"Le perdant est : "<<Game.getActivePlayer()<<endl ;
}
//put all 2gather with minimax bot
void isolaGamepveMiniMax(int Size,int nbp,int nbm)
{
    cout<<" PVE Game minimax bot "<<endl ;
    IsolaGame Game(Size,nbp,nbm) ;
    while(!(Game.EndGame()))
    {
        //display of game
        Game.DisplayGame();
        //move of active player
        Game.MovePlayerInGameIAWithMiniMax();


        Game.IADestroyCaseInGame();
        system("CLS") ;
       // Game.DisplayGame();
        //destruction of case
        //Game.IADestroyCaseInGame();
        system("CLS") ;
        Game.DisplayGame();
        //pass to next player
        Game.GivePlayerTurn();
        system("CLS") ;
    }
    cout<<"Le perdant est : "<<Game.getActivePlayer()<<endl ;
}
void affiche_annexe ()
{
    cout<<"pour le movement tu va utiliser :"<<endl;
    cout<< "0--> fixed"<<endl;
    cout<< "1--> sw"<<endl;
    cout<< "2--> sud"<<endl;
    cout<< "3--> se"<<endl;
    cout<< "4--> Ouest"<<endl;
    cout<< "5--> fixed"<<endl;
    cout<<"6 -->est"<<endl;
    cout<< "7 -->nw"<<endl;
    cout<< "8--> North"<<endl;
    cout<< "9--> ne"<<endl<<endl;
}

int main()
{
    int p=1;
    do
    {
        int n=0,m=0,l=0;
        do
        {
            cout<<"veuillez entrer les parametres correctement"<<endl;
            cout <<"donner la dimension de l'echiquier"<<endl;
            cin >> n;
            cout <<"donner le nombre des joueurs"<<endl;
            cin >> m;
            cout <<"donner le nombre des joueurs machine"<<endl;
            cin >> l;
        }while((n<4)||(n>10) || (m<=1) || (m>((n*n)/2)) || (l>=m));


        if (l==0)
        {
            system("CLS") ;
            srand(time(NULL)) ;
            affiche_annexe();
            isolaGamepvp(n,m);
        }

        else
       {

           int k=0;
           while (k!=1 && k!=2)
           {

               cout <<"tu a choisi de jouer contre la machine "<<endl;
               cout<<"cliquer sur (1) pour le niveau facile et (2) pour le niveau difficile"<<endl;
               cin>>k;
           }
           if (k==1)
           {

                system("CLS") ;
               srand(time(NULL)) ;
               affiche_annexe();
               isolaGamepve(n,m,l);
           }
           else
           {

               system("CLS") ;
               srand(time(NULL)) ;
               affiche_annexe();
               isolaGamepveMiniMax(n,m,l) ;
           }


        }

        cout <<" si vous voulez jouer une autre fois taper sur (1)"<<endl;
        cin>>p;
    }while(p==1);
    return 0 ;


}

