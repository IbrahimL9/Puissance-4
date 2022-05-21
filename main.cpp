#include "jeu.h"
#include <iostream>
#include<cstdlib>
#include<ctime>

int main()
{
    grille G;
    joueur j1;
    joueur j2;
    initGrille (G);
    int col;

  j1.s='O';
  j2.s='X';
  std::cout<<"Donnez le nom du joueur1 : ";
  std::cin>>j1.joueur;
  std::cout<<"Donnez le nom du joueur2 : ";
  std::cin>>j2.joueur;
  int nbc=0;
  char x;
  char s;
  std::string aux;
  srand(time(NULL));
  int nbc_ia=0;
  if (((rand()%2)+1)==1)
   { aux=j1.joueur;
     x=j1.s;
   }
  else {
        aux=j2.joueur;
        x=j2.s;}

        do{
            affiche (G);
            std::cout<<aux;
         if ((aux=="ia") or (aux=="ia2"))
         {
            if(x=='X') s='O';
            else s='X';
                joue_IA(G,x,s,nbc_ia);
                std::cout<<std::endl;

         }

        else
        {
        saisie(G,col);
        joue(G,x,col);
        }


      if (not gagner(G,x))
      {
        change_player (j1,j2,aux,x);
        ++nbc;
      }
    } while ( (not gagner(G,x)) and (nbc<42));

    affiche (G);
    if (nbc==42) std::cout<<"Partie null."<<std::endl;
    else if (x==j1.s) std::cout<<j1.joueur<<" a gagné !"<<std::endl;
    else std::cout<<j2.joueur<<" a gagné !"<<std::endl;
}
