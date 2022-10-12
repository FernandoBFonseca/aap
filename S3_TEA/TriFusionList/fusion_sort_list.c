#include <string.h>
#include <stdio.h>
#include "test_utils.h"
#include "list_v2.h"

#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_list getp_elt(T_list l, int i);
void fusionnerList(T_list l, int d, int m, int f);


T_list fusionSortList(T_list l, int n) {


    if(n==1) return l;
	int m = n/2; 

	T_list leftArray = fusionSortList(l, m);
	T_list rightArray = fusionSortList(getp_elt(l,m), (n-m));	

	fusionnerList(l, 0, m-1, n-1);

	return l;
}


T_list getp_elt(T_list l, int pos) {
	int i=0;
	T_list aux = l;
	
	while (i < pos) {
		aux = aux->pNext;
		i++;
	}
	
	return aux;
}

void fusionnerList(T_list l, int d, int m, int f) {
	T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99) 
	int i, j, k=0;

	T_list listIni = getp_elt(l, d);
	T_list listAux = listIni;

	for(j=d; j<=f; j++){
		aux[k++] = listAux->data;
		listAux = listAux->pNext;
	}

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
    
		if (aux[i] <= aux[j]){
			getp_elt(listIni, k++)->data = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		getp_elt(listIni, k++)->data = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
  
	for (; i <= m - d; getp_elt(listIni, k++)->data = aux[i++]); // le reste du tableau gauche
	for (; j <= f - d; getp_elt(listIni, k++)->data = aux[j++]); // le reste du tableau droit
}





