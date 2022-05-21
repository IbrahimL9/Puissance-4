#include "jeu.h"
#include <iostream>
void copie (grille &C,grille G)
{
    for(int l=0;l<maxlignes;++l)
        for(int c=0;c<maxcolonnes;++c)
         C[l][c]=G[l][c];
}

//on simule dans la copie en essayant toutes les cases
int anticipe (grille G,char i,char j)
{
    grille A;
    grille B;
    grille C;
    grille D;
    grille E;
    int score=0;
    int w=0;
    int c1=-1;


        for(int c=1;c<=maxcolonnes;++c)
             {
                 score=0;
                 //verifier si la colonne est pleine
                if (G[0][c-1]==' ')
              {
              //pour toujours travailler sur la grille initiale en essayant toutes les colonnes
                 copie (C,G);
                 joue(C,i,c);

               for(int y=1;y<=maxcolonnes;++y)
               {
                   //pour essaier tout les cas possible
                   copie(B,C);
                   if (G[0][y-1]==' ')
                 { joue(B,j,y);
                   //pour eviter cette colonne si l'ennemi peut gagner au prochain tour
                   if (gagner(B,j))
                          score=score-10000;

                    for(int p=1;p<=maxcolonnes;++p)
                   {
                       copie(A,B);
                      if(G[0][p-1]==' ')
                      {
                        joue(A,i,p);
                       if (gagner(A,i))
                       score+=10;

                     for(int b=1;b<=maxcolonnes;++b)
                      {
                          copie (D,A);
                       if (G[0][b-1]==' ')
                      {   joue(D,j,y);
                          if (gagner(D,j))
                          score-=10;
                     for(int k=1;k<=maxcolonnes;++k)
                      {
                          copie (E,D);
                        if(G[0][k-1]==' ')
                         joue(E,i,k);
                        if (gagner(E,i))
                          score+=10;
                      }

                      }
                    }
                  }
                 }
               }
             }
            }
            //on verifie si c'est la case ou on a le plus gagné
                        if ((score>=0) and (score>w))
                       {
                        w=score;
                        c1=c;
                       }
           }

     return c1;

}
void joue_IA (grille &G,char i,char j,int &nbc_ia)
{
    grille C;
    bool verif=false;
    //essaier de prendre le controle du mileu
    if (nbc_ia<2)
    {
        //imposer le premier coup a la 3e colonne
        if (nbc_ia==0)
            joue(G,i,4);

        else if (G[maxlignes-1][3]==i) joue(G,i,4);
        else if (G[maxlignes-1][2]==' ') joue(G,i,3);
        else if (G[maxlignes-1][4]==' ') joue(G,i,5);
    }

       else
    {
        int g=1;
        //verifier si on peut gagner
          while ((g<=maxcolonnes) and (not verif))
          {
           //pour ne pas prendre en compte les modifications de la copie
           copie(C,G);
               joue(C,i,g);
           if ( (gagner(C,i)==true) and (G[0][g-1]==' '))
           {
               joue(G,i,g);
               verif=true;
           }
           else ++g;
          }


    //verifier si on peut bloquer
        int s=1;
      while ((s<=maxcolonnes) and (not verif))
          {
           copie(C,G);
          joue(C,j,s);
           if ( (gagner(C,j)==true) and (G[0][s-1]==' '))
           {
               joue(G,i,s);
               verif=true;
           }
           else ++s;
          }

     //on anticipe la meilleure colonne
     if ((not verif) and (anticipe (G,i,j)!=-1))
       joue(G,i,anticipe (G,i,j));

      //sinon en joue aléatoirement
      else if(not verif)
      {
        int x;
          do {
               x=rand()%8;
             } while (G[0][x]!=' ');
          joue (G,i,x);
      }

   }
   ++nbc_ia;
}
