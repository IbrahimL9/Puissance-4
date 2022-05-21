#include "jeu.h"
#include <iostream>

void initGrille (grille &G)
{
  for(int l=0;l<maxlignes;++l)
    for(int c=0;c<maxcolonnes;++c)
      G[l][c]=' ';
}

void affiche (grille G)
{
    std::cout<<" ";
    for (int i=1;i<=maxcolonnes;++i)
        std::cout<<" "<<i;
    std::cout<<std::endl;
   for(int l=0;l<maxlignes;++l)
    {
      std::cout<<l+1;
    for(int c=0;c<maxcolonnes;++c)
      std::cout<<"|"<<G[l][c];
    std::cout<<"|"<<std::endl;
     }
}


int indvide (grille G,int c)
  {
      bool stop=false;
      int ind=0;
      int i=maxlignes;
       while ((not stop) and (i>0))
       {
           if (G[i-1][c-1]== ' ')
            {
               ind= i-1;
               stop =true;
            }
            --i;
       }
       return ind;
  }
  void saisie (grille G , int &c)
  {

    do
    {
        std::cout<<" choisissez la colonne : ";
        std::cin>>c;

    } while ( ((c>7) or (c<0)) or (G[0][c-1]!=' '));


  }
void joue (grille &G,char s, int c)
{

    G[indvide(G,c)][c-1]=s;
}

bool verif_horz (grille G,char s)
{
    bool gagne=false;
    for(int l=0;l<maxlignes;++l)
       {
          for(int c=0;c<maxcolonnes-3;++c)
         {
            if ( (G[l][c]==s) and (G[l][c+1]==s) and (G[l][c+2]==s) and (G[l][c+3]==s))
                gagne= true;
         }
      }
    return gagne;
}

bool verif_vert (grille G,char s)
{
    bool gagne=false;
    for(int c=0;c<maxcolonnes;++c)
       {
          for(int l=0;l<maxlignes-3;++l)
         {
            if ( (G[l][c]==s) and (G[l+1][c]==s) and (G[l+2][c]==s) and (G[l+3][c]==s))
                gagne= true;
         }
      }
    return gagne;
}

bool diagonal_droit (grille G,char s)
{
     bool gagne=false;
    for(int l=0;l<maxlignes-3;++l)
       {
          for(int c=0;c<maxcolonnes-3;++c)
         {
            if ( (G[l][c]==s) and (G[l+1][c+1]==s) and (G[l+2][c+2]==s) and (G[l+3][c+3]==s))
                gagne= true;
         }
      }
    return gagne;
}

bool diagonal_gauche(grille G,char s)
{
    bool gagne=false;
    for(int l=0;l<maxlignes-3;++l)
       {
          for(int c=3;c<maxcolonnes;++c)
         {
            if ( (G[l][c]==s) and (G[l+1][c-1]==s) and (G[l+2][c-2]==s) and (G[l+3][c-3]==s))
                gagne= true;
         }
      }
    return gagne;
}
void change_player (joueur j1,joueur j2,std::string &aux,char &s)
{
   if (aux == j1.joueur)
     {
         aux=j2.joueur;
         s=j2.s;
     }
    else {
         aux=j1.joueur;
         s=j1.s;
         }

}

bool gagner (grille G,char s)
{
    return ((verif_horz ( G,s)) or (verif_vert (G,s)) or (diagonal_droit (G,s)) or (diagonal_gauche(G,s)));
}
