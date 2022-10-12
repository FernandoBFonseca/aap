#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 
#include "../include/check.h"

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "avl.h"

int main(int argc, char ** argv) {

	//Vérifie si l'argument est valide
	if(argc < 3){
		printf("Not a valid input.\n");
		printf("Please insert file with names path and the number of names with de comand.\n");
		printf("Exemple: ./displayAVL.exe PrenomsV1.txt 10\n");
		NL();
		return 1;
	}

	FILE *fpNames;

	fpNames = fopen(argv[1], "r");
	CHECK_IF(fpNames, NULL, "File not found");

	int n = atoi(argv[2]); 

	T_avl root = NULL; 
	
	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	outputPath = "Partie1/output";
	
	char name[30];
	//Boucle qui insère un nouveau nom dans l'arbre 
	// et crée une représentation graphique de l'arbre
	// actualisée pour chaque nouveau mot 
	for(int i = 0;i<n;i++){

		fgets(name, sizeof(name), fpNames);
		insertAVL(&root, name);
		createDotAVL(root, "displayAVL");

	}

	//Ferme le fichier et libère la mémoire
	fclose(fpNames);
	freeAVL(root);

	return 0;
}







