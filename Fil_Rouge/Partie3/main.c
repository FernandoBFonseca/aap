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
#include "anagrams.h"

int main(int argc, char ** argv) {
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
	int j;
	//Construction de l'arbre
	while(fgets(name, sizeof(name), fpNames)){
		
		j = 0;
		while(name[j] != '\n'){
			if(name[j] == '\0') break;
			j++;
		}
		name[j] = '\0';
		insertAVL(&root, name);
	}

	fclose(fpNames);
	

	int nb = nbAnagrams(root);
	printf("Nombre de mots du dictionnaire disposant d’anagrammes = %d", nb); NL(); NL();
	
	//Crée une liste chaînée auxiliaire contenant 
	//tous les anagrammes de l'arbre
	T_anagramList l = NULL;
	getAnagrams(root, &l);
	printAnagrams(l);

	freeAnagrams(l);
	freeAVL(root);
	
	return 0;
}