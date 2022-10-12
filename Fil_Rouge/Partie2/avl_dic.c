#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h> 

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

//#define DEBUG
#include "../include/check.h"

#include "elt.h" // T_elt 
#include "avl_dic.h" // prototypes 
#include "list_v2.h"

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
    T_list words;
    T_elt sig; // signature du mot
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
	pAux->words = addNode(e, pAux->words); 
	pAux->sig = eltSig(e);
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
	int deltaH = 0;
	T_elt sig_e = eltSig(e);
	// On compare l'élément et la racine 
	if (eltcmp(sig_e, (*pRoot)->sig) < 0) {
	// On insère dans le sous-arbre gauche
		deltaH = insertAVL(&(*pRoot)->l, e); 
		(*pRoot)->bal += deltaH;
	} else  if(eltcmp(sig_e, (*pRoot)->sig) > 0) {
	// On insère dans le sous-arbre droit
		deltaH = insertAVL(&(*pRoot)->r, e); 
		(*pRoot)->bal -= deltaH;
	} else if (eltcmp(sig_e, (*pRoot)->sig) == 0){
	// On insère dans la list de mots
		if(!inListIte(e, (*pRoot)->words))
			(*pRoot)->words = addNode(e, (*pRoot)->words);
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
		printf("%s\n", toString(root->sig));
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
	
	return 1 + nbNodesAVL(root->l) + nbNodesAVL(root->r);
}

int depthNodeAVL(T_avl root, T_elt e){
	// profondeur d'un nœud
	int depth = -1;

	if(root == NULL) return depth;
	
	if(eltcmp(e, root->sig) == 0) return depth + 1;

	depth = depthNodeAVL(root->l, e);
	if (depth >= 0) return depth +1;

	depth = depthNodeAVL(root->r, e);
	if (depth >= 0) return depth +1;

	return depth;

}


T_avlNode * searchAVL_rec(T_avl root, T_elt e){
	// recherche récursive
	// ordre de récurrence : hauteur de l'arbre 	
	int test; 

	// base 
	if (root== NULL) return NULL; 
	else {
		test = eltcmp(e,root->sig); 
		if (test == 0) return root; // trouvé ! 
		else if (test <= 0) return searchAVL_rec(root->l,e);
		else return searchAVL_rec(root->r,e);
	}
}


T_avlNode * searchAVL_it(T_avl root, T_elt e){
	// recherche itérative

	int test;
	while(root!=NULL) {	
		test = eltcmp(e,root->sig);
		if (test ==0) return root;
		else if  (test <= 0) root = root->l; 
		else root = root->r; 
	}

	// pas trouvé (ou vide)
	return NULL;  
}

int lenWords_AVL(T_avl root){
	//Trouver la taille du plus grand mot de l'arbre
	if(root ==NULL) return 0;

	return MAX3(strlen(root->sig), lenWords_AVL(root->l), lenWords_AVL(root->r));
}
int nbWords_AVL(T_avl root){
	// nb de mot d'un arbre (y compris les feuilles) 
	if (root == NULL) 
		return 0;
	
	return getSizeRec(root->words) + nbWords_AVL(root->l) + nbWords_AVL(root->r);
	
}
int thereIsWord(T_avlNode *node, T_elt word){
	//Teste si il y a un mot donné 
	//dans la liste de mots d'un noeud donné.
	return inListIte(word, node->words);
}

void print_SearchAVL(T_avl root, T_elt word){
	//Fonction permettant de rechercher un certain mot dans l'arbre 
	//et d'afficher les informations correspondantes
	
	T_elt sig = eltSig(word);
	printf("À la recherche de %s avec signature: %s", toString(word), sig); NL();
	clock_t begin = clock();
	T_avlNode *node = searchAVL_rec(root, sig);
	clock_t end = clock();
	
	//Teste si le nœud est nul ou s'il n'y a pas le mot
	//(même s'il a sa signature dans l'arbre)
	if(node == NULL || !thereIsWord(node, word)){
		printf("Mot pas trouvé :("); NL();
		return;
	}
	
	printf("Liste des mots de même signature:"); NL();
	showList(node->words); NL();

	printf("La profondeur du noeud est: %d", depthNodeAVL(root, sig)); NL();

	double time_spent = 1000.0*(end-begin)/CLOCKS_PER_SEC;
	printf("Temp nécessaire pour trouver ce mot: %.3f ms", time_spent); NL();

}

void freeAVL(T_avl root){

	if(root == NULL) return;

	freeAVL(root->l);
	freeAVL(root->r);

	freeList_rec(root->words);
	free(root);

	return;

}
