#pragma once

#include <array>
#include <string>

struct joueur
{
    std::string joueur;
    char s;
};


const int maxlignes = 6;
const int maxcolonnes = 7;
using ligne = std::array <char, maxcolonnes>;
using grille = std::array <ligne, maxlignes>;

void initGrille(grille& G);
void affiche(grille G);

void saisie(grille G, int &c);
//sert   demander de saisir  une colonne et v�rifier s'il est pleine ou pas

int indvide (grille G,int c);
//chercher le bon endroit pour placer le jeton dans une colonne

void joue(grille& G, char s, int c);
// sert   jouer tout simplement

void change_player(joueur j1, joueur j2, std::string& aux, char& s);
// changer le joueur


bool gagner(grille G, char s);
// les 4 positionnements possibles pour gagner une partie

void joue_IA(grille& G, char i, char j,int &nbc_ia);
//cette fonction est pour l'ia sert   bloquer le joueur de gagner au cas ou il a  rassembl  3 jetons (verti,horiz,diago_d_g) au meme temps sert   voir si on
//peut  gagner avec un coupp

