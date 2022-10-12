#include <assert.h> // assert

#include "../include/check.h" 

#include "../include/traces.h" 

#include "list_v2.h"
#include "test.h" 

T_list genTestList(){

	T_list l = NULL;

	for(int i = 5;i > 0; i--){
		l = addNode(i,l);
	}

	return l;
}


T_list genDuplicatedTestList(){

	T_list l = NULL;
	for(int i = 5;i > 0; i--){
		l = addNode(i,l);
		if(i%2) l = addNode(i,l);
	}

	return l;
}
void test(){

    T_list l = genTestList();

	printf("Testing new functions for lists\n");
	printf("Exemple list: ");
	showList(l); NL();

	printf("Size of the list (Iterative): %d\n", getSizeIte(l));
    printf("Size of the list (Recursive): %d", getSizeRec(l));
    NL();

    printf("Adding %d to the tail (Iterative): ", 7);
    l = tailAddNodeIte(7, l); showList(l); NL();
    printf("Adding %d to the tail (Recursive): ", 9);
    l = tailAddNodeRec(9, l); showList(l); NL();

	printf("Sort adding %d to the list (Iterative): ",6);
	l = sortAddNodeIte(6,l); showList(l); NL();
	printf("Sort adding %d to the list (Recursive): ",8);
	l = sortAddNodeRec(8,l); showList(l); NL();

	printf("Is %d in the list? (Iterative) %d (True)\n", 9, inListIte(9,l));
	printf("Is %d in the list? (Recursive) %d (False)\n", 10, inListIte(10,l));
	NL();

	T_list l_dup1 = genDuplicatedTestList();
	printf("New exemple list with duplicates: ");
	showList(l_dup1); NL();

	printf("Removing duplicates (Iterative): ");
	l_dup1 = removeDuplicatesIte(l_dup1); showList(l_dup1); NL();
	
	T_list l_dup2 = genDuplicatedTestList();
	printf("Removing duplicates (Recursive): ");
	l_dup2 = removeDuplicatesRec(l_dup2); showList(l_dup2); NL();

	freeList(l); freeList(l_dup1); freeList(l_dup2);

	return;
}