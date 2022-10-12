#include "anagrams.h"
#include "../include/traces.h" 

/*
typedef struct anagramNode {
	T_list words;
	struct anagramNode *pNext;
} T_anagramNode, * T_anagramList;
*/

static T_anagramNode * newNode(T_list e) {
	// Créer une nouvelle cellule contenant l'élément e

	T_anagramNode * pNode; 
	CHECK_IF(pNode = malloc(sizeof(T_anagramNode)), NULL, "malloc allocateNode"); 
	pNode->words = e; 
	pNode->pNext = NULL;

	return pNode;
}

T_anagramList sortAddNodeAna(T_list e, T_anagramList l){
    //Insère une liste de mots par ordre croissant dans 
    //la liste d'anagrammes 

    if(l!=NULL){
		T_anagramList next, aux = l;

        while(aux && aux->pNext && getSizeRec(e) > getSizeRec(aux->pNext->words)){
            aux = aux->pNext;
        }

        next = aux->pNext;
		aux->pNext = newNode(e);
		aux->pNext->pNext = next;

		return l;
	}
    else return newNode(e);
}

void getAnagrams(T_avl root, T_anagramList *pL){

    //cas de base
    if(root == NULL) return;

    //Si on a des anagrammes dans la liste de mots
    if(getSizeRec(root->words) > 1){
        *pL = sortAddNodeAna(root->words, *pL);
    }
    
    getAnagrams(root->l, pL); 
    getAnagrams(root->r, pL);

    return;
}

void printAnagrams(T_anagramList anagramsList){
    //Affiche les anagrammes par ordre décroissant 

    if(anagramsList == NULL) return;

    printAnagrams(anagramsList->pNext);
    showList_rec(anagramsList->words); NL();

    return;
}

void freeAnagrams(T_anagramList l){

    if(l == NULL) return;

    freeAnagrams(l->pNext);

    free(l);

    return;
}