#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"	// T_elt 
#include "stack_cs.h"


int main(int argc, char ** argv) {
	T_stack s;
	T_elt e;  

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Développer les fichiers stack_sc.h et stack_sc.c
	// Développer un programme de test permettant d’utiliser ces fonctions
	/////////////////////////////////////////////////////////////////////////


 	// Récupérer une pile d'exemple
	s = exampleStack(5); 
	NL();
	// Afficher la pile
	showStack(&s);
	NL();
	
	// Ajouter un élément 
	push(genElt(),&s);
	NL();
	
	// Afficher la pile
	showStack(&s);
	NL();
	
	// Afficher le sommet 
	printf("Sommet : %s\n", toString(top(&s)));

	// Dépiler un élément
	e = pop(&s);

	// Afficher l'élément extrait
	printf("Elt extrait : %s\n", toString(e));

	// Afficher la pile
	showStack(&s);
	NL();

	// Vider la pile
	emptyStack(&s);
	NL();

 	// Afficher la pile 
	showStack(&s);
	NL();

	return 0;
}







