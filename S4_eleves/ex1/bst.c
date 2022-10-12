#include <assert.h>
#include <sys/stat.h>
#include <string.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

//#define DEBUG
#include "../include/check.h"

#include "elt.h" // T_elt 
#include "bst.h" // prototypes 

char * outputPath = "."; 

/*
typedef struct tNode{
	T_elt val;
	struct tNode *l;
	struct tNode *r;
} T_bstNode, *T_bst;
*/

static T_bstNode * newNodeBST(T_elt e) {
	// Créer une nouvelle cellule contenant l'élément e	
	T_bstNode *pNoeud;

	pNoeud = (T_bstNode*) malloc(1*sizeof(T_bstNode));
	CHECK_IF(pNoeud, NULL, "error malloc in newNodeBST");
	pNoeud->val = eltdup(e);
	pNoeud->l = NULL;
	pNoeud->r = NULL;

	return pNoeud; 
}

T_bst insertBST(T_bst root, T_elt e) {
	// ordre de récurrence ? hauteur 
	// cas de base ? arbre de jauteur nulle ou -1
	// cas général 

	if(root == NULL) {
		return newNodeBST(e);
	}
	int test = eltcmp(e, root->val);
	
	if(test > 0){
		root->r = insertBST(root->r, e);
	}
	else{
		root->l = insertBST(root->l, e);
	}
	
	return root;

}

void printBST(T_bst root, int indent) {
	// Affiche la racine de l'arbre passé en paramètre avec un niveau d'indentation proportionnel à la profondeur du sous-arbre 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 
	
	if(root != NULL){
		printBST(root->r,indent+1);

		for(int i=0; i<indent; i++) printf("\t");
		printf("%s\n",toString(root->val));

		printBST(root->l,indent+1);
	}
}

T_bstNode * searchBST_rec(T_bst root, T_elt e){
	// recherche récursive

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	if(root == NULL) return NULL;
		

	int test = eltcmp(e, root->val);
	T_bst pAux = root;

	if(test==0) return root;
	if(test > 0) pAux =root->r;
	if(test < 0) pAux =root->l;

	return searchBST_rec(pAux,e);

}

T_bstNode * searchBST_it(T_bst root, T_elt e){
	// recherche itérative
	T_bst pAux = root;
	int test;

 	while (pAux !=NULL){
		test = eltcmp(e, pAux->val);

		if(test==0) return pAux;
		if(test > 0) pAux = pAux->r;
		if(test < 0) pAux = pAux->l;
	}

	return NULL;
	
}

int heightBST(T_bst root){
	// hauteur d'un arbre 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	int l,r; 

	if (root == NULL) return -1;

	l = heightBST(root->l);
	r = heightBST(root->r);

	return 1 + ((l >= r) ? l : r); 
	
}
	
	
	int nbNodesBST(T_bst root){
	// nb de noeuds d'un arbre (y compris les feuilles) 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	if (root == NULL) return 0;
	
	return 1 + nbNodesBST(root->l) + nbNodesBST(root->r);
}

int nbLeavesBST(T_bst root){
	// nb de feuilles 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	if (root == NULL) return 0;

	if ((root->l == NULL) && (root->r == NULL)) return 1;

	return nbLeavesBST(root->l) + nbLeavesBST(root->r);
}

T_bstNode * minBST(T_bst root){
	// recherche du minimum d'un arbre 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	assert(root != NULL); 

	if (root->l==NULL) return root;

	else return minBST(root->l); 
}

T_bstNode * maxBST(T_bst root){
	// recherche du maximum d'un arbre 
	// en itératif 

	assert(root != NULL); 

	if (root->r==NULL) return root;
	 
	else return maxBST(root->r); 
}

int areEqualsBST(T_bst root1, T_bst root2){
	// les arbres ont la même structure et les mêmes éléments dans chaque noeud 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	return 0; 
}

int areIsomorphicBST(T_bst root1, T_bst root2){
	// les arbres ont la même structure

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	return 0; 
}

T_bst copyBST(T_bst root){
	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	return NULL; 
}

void printPreOrderBST(T_bst root) {
	// LRN

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");	
}

#define DERECURSIVATION
#ifndef DERECURSIVATION
void printInOrderBST(T_bst root) {
	// LNR

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");
}

void printPostOrderBST(T_bst root) {
	// NLR

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");
}
#endif

#ifdef DERECURSIVATION
void printInOrderBST(T_bst root) {
	// LNR avec suppression de l'appel récursif terminal 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");
}

void printPostOrderBST(T_bst root) {
	// NLR avec suppression de l'appel récursif terminal 

	// ordre de récurrence ? 
	// cas de base ?
	// cas général 

	TOUCH_HERE("Ben là, c'est à vous ! \n");
}
#endif 

static void  genDotBST(T_bst root, FILE *fp) {
	// Attention : les fonction toString utilisent un buffer alloué comme une variable statique 
	// => elles renvoient toujours la même adresse 
	// => on ne peut pas faire deux appels à toString dans le même printf()

    fprintf(fp, "\t%s",toString(root->val)); 
    fprintf(fp, " [label = \"{<c> %s | { <g> | <d>}}\"];\n",toString(root->val));
    if (root->r == NULL && root->l == NULL) {
        fprintf(fp, "\t%s", toString(root->val)); 
		fprintf(fp, " [label = \"{<c> %s | { <g> NULL | <d> NULL}}\"];\n", toString(root->val));
	}
    else if (root->r == NULL) {
        fprintf(fp, "\t%s", toString(root->val));
		fprintf(fp, " [label = \"{<c> %s | { <g> | <d> NULL}}\"];\n", toString(root->val));
	}
	else if ( root->l == NULL) {
        fprintf(fp, "\t%s",toString(root->val));
		fprintf(fp, " [label = \"{<c> %s | { <g> NULL | <d> }}\"];\n", toString(root->val));
	}
	
    if (root->l) {
        fprintf(fp, "\t%s",toString(root->val));
		fprintf(fp, ":g -> %s;\n", toString(root->l->val));
        genDotBST(root->l, fp);
    }

    if (root->r) {
        fprintf(fp, "\t%s",toString(root->val));
		fprintf(fp,":d -> %s;\n", toString(root->r->val));
        genDotBST(root->r, fp);
    }
}


void createDotBST(const T_bst root, const char *basename) {
	static char oldBasename[FILENAME_MAX + 1] = "";
	static unsigned int noVersion = 0;

	char DOSSIER_DOT[FILENAME_MAX + 1]; 
	char DOSSIER_PNG[FILENAME_MAX + 1]; 

	char fnameDot [FILENAME_MAX + 1];
	char fnamePng [FILENAME_MAX + 1];
	char	cmdLine [2 * FILENAME_MAX + 20];
	FILE *fp;
	struct stat sb;
	

	// Au premier appel, création (si nécessaire) des répertoires
	// où seront rangés les fichiers .dot et .png générés par cette fonction	

	// il faut créer le répertoire outputPath s'il n'existe pas 
	if (stat(outputPath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
    } else {
        printf("Création du répertoire %s\n", outputPath);
		mkdir(outputPath, 0777);
    }

	// il faut créer les répertoires outputPath/png et /dot 
	sprintf(DOSSIER_DOT, "%s/dot/",outputPath);
	sprintf(DOSSIER_PNG, "%s/png/",outputPath);

	if (oldBasename[0] == '\0') {
		mkdir(DOSSIER_DOT,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
		mkdir(DOSSIER_PNG,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	}

	 // S'il y a changement de nom de base alors recommencer à zéro
	 // la numérotation des fichiers 

	if (strcmp(oldBasename, basename) != 0) {
		noVersion = 0;
		strcpy(oldBasename, basename); 
	}

	sprintf(fnameDot, "%s%s_v%02u.dot", DOSSIER_DOT, basename, noVersion);
	sprintf(fnamePng, "%s%s_v%02u.png", DOSSIER_PNG, basename, noVersion);

	CHECK_IF(fp = fopen(fnameDot, "w"), NULL, "erreur fopen dans saveDotBST"); 
	
	noVersion ++;
    fprintf(fp, "digraph %s {\n", basename);
 	fprintf(fp, 
		"\tnode [\n"
			"\t\tfontname  = \"Arial bold\" \n"
			"\t\tfontsize  = \"14\"\n"
			"\t\tfontcolor = \"red\"\n"
			"\t\tstyle     = \"rounded, filled\"\n"
			"\t\tshape     = \"record\"\n"
			"\t\tfillcolor = \"grey90\"\n"
			"\t\tcolor     = \"blue\"\n"
			"\t\twidth     = \"2\"\n"
			"\t]\n"
		"\n"
		"\tedge [\n"
			"\t\tcolor     = \"blue\"\n"
		"\t]\n\n"
	);

    if (root == NULL)
        fprintf(fp, "\n");
    else
        genDotBST(root, fp);

    fprintf(fp, "}\n");	
    fclose(fp);

    sprintf(cmdLine, "dot -Tpng  %s -o %s", fnameDot, fnamePng);
    system(cmdLine);

    printf("Creation de '%s' et '%s' ... effectuee\n", fnameDot, fnamePng);
}


