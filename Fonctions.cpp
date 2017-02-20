#define _CRT_SECURE_NO_WARNINGS
#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "unittest.h"
#define VIDE '-'


// -----------------  Début Fonctions de vérification de victoire ----------------------//
 
void initialiserTestVictoireLigne(int tab[10][10]) {
	int i, j;

	for (i = 4; i < 5; i++) {	// ligne 4
		for (j = 0; j < 9; j++) {	// toutes les colonnes sauf derniere
			tab[i][j] = 'X';
		}
	}
	tab[4][9] = VIDE;
	for (i = 0; i < 4; i++) {	// Lignes 0 à 3
		for (j = 0; j < 10; j++) {	// toutes les colonnes
			tab[i][j] = VIDE;
		}
	}
	for (i = 5; i < 10; i++) {	// Lignes 5 à 9
		for (j = 0; j < 10; j++) {	// toutes les colonnes
			tab[i][j] = VIDE;
		}
	}
}

void initialiserTestVictoireColonne(int tab[10][10]) {
	int i, j;

	for (i = 0; i < 9; i++) {	// toutes les lignes
		for (j = 0; j < 1; j++) {	// colonne 1
			tab[i][j] = 'O';
		}
	}

	for (i = 0; i < 10; i++) {		// toutes les lignes
		for (j = 1; j < 10; j++) {	//toutes les colonne sauf la 1ere
			tab[i][j] = VIDE;
		}
		tab[9][0] = VIDE;
	}
}

void initialiserTestVictoireSimple(int tab[10][10]){

	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			tab[i][j] = VIDE;
		}
	}
	tab[3][0] = 'X', tab[3][1] = 'X', tab[4][1] = 'X';
	tab[5][1] = 'X', tab[5][2] = 'X'; tab[5][3] = 'X';
	tab[4][4] = 'X', tab[3][5] = 'X', tab[3][6] = 'X';
	tab[3][7] = 'X', tab[3][8] = 'X', tab[4][8] = 'X';
	tab[5][8] = 'X', tab[6][7] = 'X', tab[7][7] = 'X';
	tab[7][8] = 'X';

}

void initialiserTestVictoireVoisins(int tab[10][10]) {

	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			tab[i][j] = VIDE;
		}
	}
	tab[3][0] = 'X', tab[3][1] = 'X', tab[4][1] = 'X';
	tab[5][1] = 'X', tab[5][2] = 'X'; tab[5][3] = 'X';
	tab[4][4] = 'X', tab[3][5] = 'X', tab[3][6] = 'X';		// Chemin victoire principal
	tab[3][7] = 'X', tab[3][8] = 'X', tab[4][8] = 'X';
	tab[5][8] = 'X', tab[6][7] = 'X', tab[7][7] = 'X';
	tab[7][8] = 'X'; 

	tab[2][8] = 'X', tab[1][8] = 'X', tab[1][7] = 'X';
	tab[3][6] = 'X', tab[3][7] = 'X';						// Chemin faux
}

void initialiserTestVictoireAssert(int tab[10][10]) {

	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			tab[i][j] = VIDE;
		}
	}
	tab[3][0] = 'X', tab[3][1] = 'X', tab[4][1] = 'X';
	tab[5][1] = 'X', tab[5][2] = 'X'; tab[5][3] = 'X';
	tab[4][4] = 'X', tab[3][5] = 'X', tab[3][6] = 'X';		// Chemin victoire principal 'X'
	tab[3][7] = 'X', tab[3][8] = 'X', tab[4][8] = 'X';
	tab[5][8] = 'X', tab[6][7] = 'X', tab[7][7] = 'X';
	tab[7][8] = 'X';/* tab[7][9] = 'X';*/

	tab[2][8] = 'X', tab[1][8] = 'X', tab[1][7] = 'X';
	tab[3][6] = 'X', tab[3][7] = 'X';						// autre chemin 'X'

	tab[9][0] = 'O', tab[9][1] = 'O', tab[8][1] = 'O';
	tab[7][1] = 'O', tab[6][2] = 'O', tab[6][3] = 'O';
	tab[4][3] = 'O', tab[3][3] = 'O', tab[2][3] = 'O';	
	tab[1][3] = 'O', tab[0][3] = 'O';						// Chemin 'O'
}

// -----------------   Fin Fonctions de vérification de victoire ----------------------//

void afficherTab(int tab[10][10]) {

	printf("%*s", 4, " ");
	for (int i = 0; i < 10; i++) {
		printf("%i  ", i); 
	}
	printf("\n");

	for (int k = 0; k < 10; k++) {
		printf("%*s", k + 1, " ");
		printf("%i ", k);

		for (int l = 0; l <10; l++) {
			printf(" %c ", tab[k][l]); 
		}
		printf(" %i", k);
		printf("\n");
	}
	printf("%*s", 13, " ");

	for (int j = 0; j < 10; j++) {
		printf("%i  ", j);
	}
	printf("\n\n\n");
}

int initialiser(int tab[10][10]) {
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			tab[i][j] = VIDE;
		}
	}
	return 0;
}

int jouerJ1(int tabJeu[10][10]) {

	int colonne;
	int ligne;
	printf("Au tour du joueur 1\n");
	printf("Choisissez une colonne : ");
	scanf("%i", &colonne);
	printf("\n");
	printf("Choisissez une ligne : ");
	scanf("%i", &ligne);
	printf("\n\n");
	while (tabJeu[ligne][colonne] != VIDE) {				// Si case déjà prise, redemander de jouer
		printf("Impossible de jouer dans cette case, recommencez\n");
		printf("Choisissez une colonne : ");
		scanf("%i", &colonne);
		printf("\n");
		printf("Choisissez une ligne : ");
		scanf("%i", &ligne);
		printf("\n\n");
	}
	tabJeu[ligne][colonne] = 'X';							//joueur UN -> remplace '-' par 'X' dans la case sélectionnée
	afficherTab(tabJeu);
	return 0;
}

int jouerJ2(int tabJeu[10][10]) {

	int colonne;
	int ligne;
	printf("Au tour du joueur 2\n");
	printf("Choisissez une colonne : ");
	scanf("%i", &colonne);
	printf("\n");
	printf("Choisissez une ligne : ");
	scanf("%i", &ligne);
	printf("\n\n");
	while (tabJeu[ligne][colonne] != VIDE) {				// Si case déjà prise, redemander de jouer
		printf("Impossible de jouer dans cette case, recommencez\n");
		printf("Choisissez une colonne : ");
		scanf("%i", &colonne);
		printf("\n");
		printf("Choisissez une ligne : ");
		scanf("%i", &ligne);
		printf("\n\n");
	}
	tabJeu[ligne][colonne] = 'O';							//joueur DEUX -> remplace '-' par 'O' dans la case sélectionnée
	afficherTab(tabJeu);
	return 0;
}

int Jeu(int tabJeu[10][10],int tabVerif[10][10]) {

	printf("Joueur 1 (x) joue horizontalement. Joueur 2 (o) joue verticalement. \n");
	printf("Joueur 1 va commencer.\n");
	printf("\n");

	//initialiserTestVictoireLigne(tabJeu);			// Tableau ligne 0 presque complète
	//initialiserTestVictoireColonne(tabJeu);		// Tableau colonne 0 presque complète
	//initialiserTestVictoireSimple(tabJeu);		// Tableau avec chemin principal
	//initialiserTestVictoireVoisins(tabJeu);		// Tableau avec plusieurs chemins

	initialiser(tabJeu);							// initialiser toutes les valeurs du tableau de jeu à 0
	initialiser(tabVerif);							// initialiser toutes les valeurs du tableau de vérification à 0
	afficherTab(tabJeu);							// Afficher le tableau

	while (gagneJ1(tabJeu,tabVerif) == false && gagneJ2(tabJeu, tabVerif) == false) {   //condition victoire
		jouerJ1(tabJeu);
		if (gagneJ1(tabJeu, tabVerif) == true){
 			gagnant(1);
		}
		jouerJ2(tabJeu);
		if (gagneJ2(tabJeu,tabVerif) == true) {
		gagnant(2);
		}
	}

	return 0;
	}

int gagnant(int x) {
	printf("Le joueur %i a remporte la partie ! Bravo !\n\n", x);
	printf("Merci d'avoir joue a Hex!\n\n");
	exit(1);
}

void testJeu(int tabJeu[10][10], int tabVerif[10][10]) {

	initialiserTestVictoireAssert(tabJeu);								// Initialisation tableau pré-rempli
	afficherTab(tabJeu);
	assertFalse(gagneJ1(tabJeu,tabVerif), "Test victoire J1 Faux");
	assertFalse(gagneJ2(tabJeu, tabVerif), "Test victoire J2 Faux");
	jouerJ1(tabJeu);
	afficherTab(tabJeu);
	assertTrue(gagneJ1(tabJeu, tabVerif), "Test victoire J1 Vrai");
	assertFalse(gagneJ2(tabJeu, tabVerif), "Test victoire J2 Faux");

}


// -------------------- CONDITION VICTOIRE JOUEUR 1 ------------------ //

bool gagneJ1(int tab[10][10],int tabVerif[10][10]) {
	int i = 0;
	int j = 0;
	bool victoire = 0;

	for (i = 0; i < 10; i++) {			//boucle sur colonne
		for (j = 0; j < 1; j++) {		//boucle sur ligne
			if (tab[i][0] == 88) {		// si case joueur 1 sur colonne 0 => rechercher si voisin
				tabVerif[i][0] = 1;
				voisinJ1(i, j, tab, tabVerif, -1, -1);		// fonction récursive qui s'exécutera tant qu'il y aura un voisin au voisin et ainsi de suite.
															//(tabVerif = 1 si connecté au voisin précédent)
			}
		}
	}
	for (i = 0; i < 10; i++) {			// Boucle sur colonne 9 qui vérifie si une des lignes a un 1 dans tabVerif. si oui cela veut dire qu'il y a un chemin gagnant
		if (tabVerif[i][9] == 1) {
			victoire = true;
		}
	}
	initialiser(tabVerif);				// réinitialiser tabVerif à 0 partout. A chaque tour du joueur 1, la fonction vérifiera si chemin gagnant.
	return victoire;
}

int voisinJ1(int i, int j, int tabJeu[10][10], int tabVerif[10][10], int x, int y) { 
	// Parcours du tableau récursivement.
	// Si valeur 'X' associé à joueur 1 sur case x alors case x du tableau de vérification prend 1. 
	// x et y sont les coordonnées de la case appelant la fonction ( évitement de boucle infinie )
	bool voisinOK = false;	// flag 

	while (voisinOK == false) {							// boucle flag pour éviter que la fonction ne vérifie qu'un seul voisin (selon ordre de priorité d'énumération)
		if (i < 10 && i >= 0 && j < 10 && j >= 0) {		// Exécuter boucle si et ssi la case appartient bien au tableau
			if (tabJeu[i - 1][j] == 88 && !(i-1 == x && j==y) && tabVerif[i-1][j] !=1){		// voisin haut-gauche
				tabVerif[i - 1][j] = 1;
				voisinJ1(i - 1, j, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i - 1][j + 1] == 88 && !(i-1 == x && j + 1 == y) && tabVerif[i - 1][j + 1] != 1 && i - 1 >= 0 && j + 1 >= 0) {		// voisin haut-droite
				tabVerif[i - 1][j + 1] = 1;
				voisinJ1(i - 1, j + 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i][j + 1] == 88 && !(i == x && j+1 == y) && tabVerif[i][j+1] != 1 && i >= 0 && j+1 >= 0) {		// voisin droite
				tabVerif[i][j + 1] = 1;
				voisinJ1(i, j + 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i + 1][j] == 88 && !(i + 1 == x && j == y) && tabVerif[i + 1][j] != 1 && i+1>=0 && j>=0) {		// voisin bas-droite
				tabVerif[i + 1][j] = 1;
				voisinJ1(i + 1, j, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i + 1][j - 1] == 88 && !(i + 1 == x && j-1 == y) && tabVerif[i + 1][j - 1] != 1 && i+1>=0 && j-1>=0) {		// voisin bas-gauche
				tabVerif[i + 1][j - 1] = 1;
				voisinJ1(i + 1, j - 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i][j - 1] == 88 && !(i == x && j-1 == y) && tabVerif[i][j - 1] != 1 && i>=0 && j-1>=0) {		 // voisin gauche
				tabVerif[i][j - 1] = 1;
				voisinJ1(i, j - 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}
			else return 0;
		}
		voisinOK = true;
	}

	return 0;
}

// -------------------- CONDITION VICTOIRE JOUEUR 2 ------------------ //

bool gagneJ2(int tab[10][10], int tabVerif[10][10]) {
	int i = 0;
	int j = 0;
	bool victoire = 0;

	for (j = 0; j < 10; j++) {			//boucle sur ligne
		for (i = 0; i < 1; i++) {		//boucle sur colonne
			if (tab[0][j] == 79) {		// si case joueur 2 sur ligne 0 => rechercher si voisin
				tabVerif[0][j] = 2;
				voisinJ2(i, j, tab, tabVerif, -1, -1);		// fonction récursive qui s'exécutera tant qu'il y aura un voisin au voisin et ainsi de suite.
															//(tabVerif = 1 si connecté au voisin précédent)
			}
		}
	}
	for (j = 0; j < 10; j++) {			// Boucle sur ligne 9 qui vérifie si une des lignes a un 1 dans tabVerif. si oui cela veut dire qu'il y a un chemin gagnant
		if (tabVerif[9][j] == 2) {
			victoire = true;
		}
	}
	initialiser(tabVerif);				// réinitialiser tabVerif a 0 partout. A chaque tour du joueur 2, la fonction vérifiera si chemin gagnant.
	return victoire;
}

int voisinJ2(int i, int j, int tabJeu[10][10], int tabVerif[10][10], int x, int y) { 
	// Parcours du tableau récursivement.
	// Si valeur 'O' associé à joueur 1 sur case x alors case x du tableau de vérification prend 1. 
	// x et y sont les coordonnées de la case appelant la fonction ( évitement de boucle infinie )
	bool voisinOK = false;	// flag 

	while (voisinOK == false) {							// boucle flag pour éviter que la fonction ne vérifie qu'un seul voisin (selon ordre de priorité d'énumération)
		if (i < 10 && i >= 0 && j < 10 && j >= 0) {		// Exécuter boucle si et ssi la case appartient bien au tableau
			if (tabJeu[i - 1][j] == 79 && !(i - 1 == x && j == y) && tabVerif[i - 1][j] != 2) {		// voisin haut-gauche
				tabVerif[i - 1][j] = 2;
				voisinJ2(i - 1, j, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i - 1][j + 1] == 79 && !(i - 1 == x && j + 1 == y) && tabVerif[i - 1][j + 1] != 2) {			// voisin haut-droite
				tabVerif[i - 1][j + 1] = 2;
				voisinJ2(i - 1, j + 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i][j + 1] == 79 && !(i == x && j + 1 == y) && tabVerif[i][j + 1] != 2) {		// voisin droite
				tabVerif[i][j + 1] = 2;
				voisinJ2(i, j + 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i + 1][j] == 79 && !(i + 1 == x && j == y) && tabVerif[i + 1][j] != 2) {		// voisin bas-droite
				tabVerif[i + 1][j] = 2;
				voisinJ2(i + 1, j, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i + 1][j - 1] == 79 && !(i + 1 == x && j - 1 == y) && tabVerif[i + 1][j - 1] != 2) {		// voisin bas-gauche
				tabVerif[i + 1][j - 1] = 2;
				voisinJ2(i + 1, j - 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}

			if (tabJeu[i][j - 1] == 79 && !(i == x && j - 1 == y) && tabVerif[i][j - 1] != 2) {		 // voisin gauche
				tabVerif[i][j - 1] = 2;
				voisinJ2(i, j - 1, tabJeu, tabVerif, i, j);
				voisinOK = true;
			}
			else return 0;
		}
	}

	return 0;
}