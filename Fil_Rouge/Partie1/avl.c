#include <assert.h>
#include <sys/stat.h>
#include <string.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

//#define DEBUG
#include "../include/check.h"

#include "elt.h" // T_elt 
#include "avl.h" // prototypes 

char * outputPath = "."; 

/*
typedef enum {
    DOUBLE_RIGHT = -2,
    RIGHT = -1,
    BALANCED,
    LEFT,
    DOUBLE_LEFT
} T_bal;

typedef struct aNode{
	T_elt val; // élément contenu dans le noeud 
	T_bal bal; // facteur de déséquilibre
	struct aNode *l; // pointeur vers sous-arbre gauche
	struct aNode *r; // pointeur vers sous-arbre droit 
} T_avlNode, *T_avl;
*/

static T_avl newNodeAVL(T_elt e); 
static T_avlNode * rotateLeftAVL (T_avlNode * A); 
static T_avlNode * rotateRightAVL (T_avlNode * B);
static T_avlNode * balanceAVL(T_avlNode * A);

static T_avl newNodeAVL(T_elt e) {

	T_avlNode * pAux; 
	pAux = (T_avlNode *) malloc(sizeof (T_avlNode)); 
	CHECK_IF(pAux, NULL,"erreur malloc dans newNode");
	pAux->val = eltdup(e); 
	pAux->l = NULL; 
	pAux->r = NULL;
	pAux->bal = BALANCED;

	return pAux;
}


int	insertAVL (T_avlNode ** pRoot, T_elt e) {

	// cas de base
	if ((*pRoot)== NULL){
		(*pRoot) = newNodeAVL(e);
		return 1;
	}
	
	// cas général 
	int deltaH;
	// On compare l'élément et la racine 
	if (eltcmp(e, (*pRoot)->val) <= 0) {
	// On insère dans le sous-arbre gauche
		deltaH = insertAVL(&(*pRoot)->l, e); 
		(*pRoot)->bal += deltaH;
	} else {
	// On insère dans le sous-arbre droit
		deltaH = insertAVL(&(*pRoot)->r, e); 
		(*pRoot)->bal -= deltaH;
	}

	// Si l'arbre ne croît pas, on quitte
	if(deltaH ==0) return 0;
	// Sinon on balance 
	else (*pRoot) = balanceAVL(*pRoot);

	//Renvoie 1 si le nœud est déséquilibré, 0 sinon.
	return (*pRoot)->bal != BALANCED;

}


static T_avlNode * rotateLeftAVL (T_avlNode * B) {
	// rotation gauche

	T_avlNode *A = B->r;

	T_bal b_ = heightAVL(B->l) - heightAVL(A);
	T_bal a_ = heightAVL(A->l) - heightAVL(A->r);
	
	B->r = A->l;
	A->l = B;

	// Calcul des nouvelles balances
	T_bal b = b_ + 1 - MIN2(0,a_);
	T_bal a = a_ + 1 + MAX2(0,b);
	
	A->bal = a;
	B->bal = b;

	return A; 
}


static T_avlNode * rotateRightAVL (T_avlNode * A) {
	// rotation droite

	T_avlNode *B = A->l;

	T_bal a = heightAVL(B) - heightAVL(A->r);
	T_bal b = heightAVL(B->l) - heightAVL(B->r);

	A->l = B->r;
	B->r = A;

	// Calcul des nouvelles balances
	T_bal a_ = a - 1 - MAX2(0,b);
	T_bal b_ = b - 1 + MIN2(0,a_);

	A->bal = a_;
	B->bal = b_;

	return B; 

}


static T_avlNode * balanceAVL(T_avlNode * node) {
	// rééquilibrage de A

	if( node->bal == DOUBLE_LEFT){
		if( node->l->bal == RIGHT){
			// leftRightCase
			node->l = rotateLeftAVL(node->l);
			return rotateRightAVL(node);
		}
		else{
			// leftLeftCase
			return rotateRightAVL(node);
		}
	}

	if(node->bal == DOUBLE_RIGHT){
		if( node->r->bal == LEFT){
			// rightLeftCase
			node->r = rotateRightAVL(node->r);
			return rotateLeftAVL(node);
		}
		else{
			// rightRightCase
			return rotateLeftAVL(node);
		}
	}

	return node;

}

// IDEM pour ABR 
void printAVL(T_avl root, int indent) {
	int i; 
	// ordre de la récurrence : hauteur de l'arbre 
	// Affiche la racine de l'arbre passé en paramètre avec un niveau d'indentation proportionnel à la profondeur du sous-arbre 

	// pas de cas de base... 
	if (root!=NULL) {
		// afficher le sous-arbre droit avec indentation+1
		printAVL(root->r, indent+1);
		// afficher le noeud racine 
		for(i=0;i<indent;i++) printf("\t");
		printf("%s\n", toString(root->val));
		// afficher le sous-arbre gauche avec indentation+1
		printAVL(root->l, indent+1);
	}
}

int heightAVL(T_avl root){
	// hauteur d'un arbre 
	int l,r; 
	if (root == NULL) return -1;

	l = heightAVL(root->l);
	r = heightAVL(root->r);

	return 1 + ((l >= r) ? l : r); 
}

int nbNodesAVL(T_avl root){
	// nb de noeuds d'un arbre (y compris les feuilles) 
	if (root == NULL) 
		return 0;
	
	return 1+ nbNodesAVL(root->l) + nbNodesAVL(root->r);
}


T_avlNode * searchAVL_rec(T_avl root, T_elt e){
	// recherche récursive

	// ordre de récurrence : hauteur de l'arbre 	
	int test; 

	// base 
	if (root== NULL) return NULL; 
	else {
		test = eltcmp(e,root->val); 
		if (test == 0) return root; // trouvé ! 
		else if (test <= 0) return searchAVL_rec(root->l,e);
		else return searchAVL_rec(root->r,e);
	}
}


T_avlNode * searchAVL_it(T_avl root, T_elt e){
	// recherche itérative

	int test;
	while(root!=NULL) {	
		test = eltcmp(e,root->val);
		if (test ==0) return root;
		else if  (test <= 0) root = root->l; 
		else root = root->r; 
	}

	// pas trouvé (ou vide)
	return NULL;  
}


static void  genDotAVL(T_avl root, FILE *fp) {
	// Attention : les fonction toString utilisent un buffer alloué comme une variable statique 
	// => elles renvoient toujours la même adresse 
	// => on ne peut pas faire deux appels à toString dans le même printf()

	fprintf(fp, "\t\"%s\"",toString(root->val)); 
	fprintf(fp, " [label = \"{{<c> %s | <b> %d} | { <g> | <d>}}\"];\n",toString(root->val),root->bal);
	if (root->r == NULL && root->l == NULL)
	{
		fprintf(fp, "\t\"%s\"", toString(root->val));
		fprintf(fp, " [label = \"{{<c> %s | <b> %d} | { <g> NULL | <d> NULL}}\"];\n", toString(root->val),root->bal);
	}
	else if (root->r == NULL)
	{
		fprintf(fp, "\t\"%s\"", toString(root->val));
		fprintf(fp, " [label = \"{{<c> %s | <b> %d} | { <g> | <d> NULL}}\"];\n", toString(root->val),root->bal);
	}
	else if (root->l == NULL)
	{
		fprintf(fp, "\t\"%s\"",toString(root->val));
		fprintf(fp, " [label = \"{{<c> %s | <b> %d} | { <g> NULL | <d> }}\"];\n", toString(root->val),root->bal);
	}

	if (root->l)
	{
		fprintf(fp, "\t\"%s\"",toString(root->val));
		fprintf(fp, ":g -> \"%s\";\n", toString(root->l->val));
		genDotAVL(root->l, fp);
	}

	if (root->r)
	{
		fprintf(fp, "\t\"%s\"",toString(root->val));
		fprintf(fp,":d -> \"%s\";\n", toString(root->r->val));
		genDotAVL(root->r, fp);
	}
}


void createDotAVL(const T_avl root, const char *basename) {
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
        genDotAVL(root, fp);

    fprintf(fp, "}\n");	
    fclose(fp);

    sprintf(cmdLine, "dot -Tpng  %s -o %s", fnameDot, fnamePng);
    system(cmdLine);

    printf("Creation de '%s' et '%s' ... effectuee\n", fnameDot, fnamePng);
}


void freeAVL(T_avl root){

	if(root == NULL) return;

	freeAVL(root->l);
	freeAVL(root->r);

	free(root);

	return;

}