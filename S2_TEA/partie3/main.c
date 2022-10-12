#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 
#include "../include/check.h"
// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "list_v2.h"
#include "genPNG.h"

int main(int argc, char ** argv) {

	char filename[50];
	T_list l;

	printf("Input the filename: ");
	scanf("%s",filename);
	printf("Generating PNG in %s.dot\n", filename);

	printf("1-Use Exemple List\n2-Input a List\n0-Exit\n");
	int c;
	scanf("%d", &c);

	switch (c)
	{
	case 1:
		l = exempleList();
		break;
	case 2:
		l = genList();
		break;
	}
	
	CHECK_IF(l, NULL, "Wrong Usage: PNG will not be generated!!\n");
	
	printf("Generated list: "); showList(l); NL();
	generatePNG(l, filename);

	freeList(l);
	

	return 0;
}







