#include <stdio.h>
#include <assert.h>
#include <time.h> 
#include <math.h>
#include <unistd.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 
#include "../include/check.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "avl_dic.h"


int main(int argc, char ** argv) {
	//Vérifie si l'argument est valide
	if(argc < 2){
		printf("Not a valid input."); NL();
		printf("Please insert file with words path."); NL();
		printf("Exemple: ./indexation.exe Dico_03.txt"); NL();
		return 1;
	}

	FILE *fpNames;

	fpNames = fopen(argv[1], "r");
	CHECK_IF(fpNames, NULL, "File not found");

	T_avl root = NULL; 
	
	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	char name[30];
	int j, i = 0;

	clock_t begin = clock();

	//Construction de l'arbre
	while(fgets(name, sizeof(name), fpNames)){
		
		j = 0;
		while(name[j] != '\n'){
			if(name[j] == '\0') break;
			j++;
		}
		name[j] = '\0';
		insertAVL(&root, name);
		i++;
				
	}

	fclose(fpNames);

	//Afficher des informations sur l'arbre	
	clock_t end = clock();
	double time_spent = 1000.0*(end-begin)/CLOCKS_PER_SEC;

	printf("Taille des mots du dictionnaire: %d", lenWords_AVL(root)); NL();
	printf("Nombre de mots du dictionnaire: %d", nbWords_AVL(root)); NL();
	printf("Durée de construction de l'arbre: %.3f ms", time_spent); NL();
	printf("Nombre de noeuds: %d\nHauteur de l'abre: %d", nbNodesAVL(root), heightAVL(root)); NL();
	int minHeight = (int) log2(nbNodesAVL(root));
	printf("Hauteur minimale d'un arbre de %d noeuds: %d", nbNodesAVL(root), minHeight); NL();

	//Recherche de mots dans la liste
	char word[30];
	printf("--------------\n");
	printf("Saisir un mot dans l'arbre:"); NL();
	while(1){
		printf("Entrez le mot: ");
		scanf("%s", word);
		if(word[0] == '0') break;

		print_SearchAVL(root, word);

		printf("\n--------------\n");
		printf("Type 0 to end the program"); NL();

	}

	freeAVL(root);
	return 0;
}