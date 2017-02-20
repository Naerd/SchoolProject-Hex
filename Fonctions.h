#ifndef Fonctions_h
#define Fonctions_h
#include <stdio.h>
#include <stdlib.h>

// ---------- Fonctions d'affichage et de jeu ---------- //

void afficherTab(int tab[10][10]);
int initialiser(int tab[10][10]);
int jouerJ1(int tabJeu[10][10]);
int jouerJ2(int tabJeu[10][10]);
int Jeu(int tabJeu[10][10],int tabVerif[10][10]);
void testJeu(int tabJeu[10][10], int tabVerif[10][10]);

// ---------- Fin fonctions d'affichage et de jeu ---------- //

// --------------------------------------------------------- //

// ---------- Fonctions de conditions de victoire ---------- //


int voisinJ1(int i, int j, int tabJeu[10][10], int tabVerif[10][10], int x, int y);
bool gagneJ1(int tab[10][10], int tabVerif[10][10]);

int gagnant(int x);

int voisinJ2(int i, int j, int tabJeu[10][10], int tabVerif[10][10], int x, int y);
bool gagneJ2(int tab[10][10], int tabVerif[10][10]);

// ---------- Fin fonction de conditions de victoire ---------- //

// ------------------------------------------------------------- //

// ---------- Fonctions de pré-remplissage de tableau ---------- //

void initialiserTestVictoireLigne(int tab[10][10]);
void initialiserTestVictoireColonne(int tab[10][10]);
void initialiserTestVictoireSimple(int tab[10][10]);
void initialiserTestVictoireVoisins(int tab[10][10]);
void initialiserTestVictoireAssert(int tab[10][10]);

// ---------- Fin fonctions de pré-remplissage de tableau ---------- //


#endif
