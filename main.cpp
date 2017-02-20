#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unittest.h"
#include "Fonctions.h"



int main() {
	

	int verifUn[10][10]; 
	int t[10][10];			
	char réponse;

	printf("Bienvenue dans Hex !\n");									// Accueil
	printf("Voulez-vous jouer ? Repondez 1 pour oui, 0 pour non.\n");
	scanf_s("%s", &réponse, 100);										// saisie sécurisée

	while (réponse != '0' && réponse != '1') {							// Décision Menu
		printf("Tapez 1 pour jouer, 0 pour quitter le jeu.\n");
		scanf_s("%s", &réponse, 100);									// saisie sécurisée
	}

	printf("\n");

	if (réponse == '1') {												// Volonté de jouer
		Jeu(t, verifUn);
	}

	else {																// Refus de jouer
		printf("Oh quel dommage... au revoir !\n\n");
		exit(1);														// fermer le programme
	}

	// testJeu(t,verifUn);												// Fonction pour tester le jeu


	return 0;
}