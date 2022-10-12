#include <string.h>
#include <stdio.h>
#include "test_utils.h"

#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

void fusionner(T_elt t [], int d, int m, int f); 


T_data fusionSort(T_data d, int n) {


	stats.nbComparisons++;
	if(n==1) return d;

	int m = n/2; 
	T_elt * A = d.pElt; 


	T_data leftArray = fusionSort(d, m);
	T_data rightArray = fusionSort(genData(0,&(A[m])), (n-m));	

	fusionner(A, 0, m-1, n-1);

	return genData(0, A);
	
	
}

void fusionner(T_elt t [], int d, int m, int f) {
	T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99) 
	int i, j, k;
	

	memcpy(aux, &t[d], (f - d + 1) * sizeof(T_elt));	// Copie des données à fusionner
	stats.nbOperations += (f - d + 1);

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
		stats.nbComparisons+=2;
		stats.nbOperations++;
		if (aux[i] <= aux[j]) 	{
			t[d + k++] = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		t[d + k++] = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
	stats.nbOperations += (m - d - i > 0) ? m - d - i : 0;
	for (; i <= m - d; t[d + k++] = aux[i++]); // le reste du tableau gauche
	stats.nbOperations += (m - d - i > 0) ? m - d - i : 0;
	for (; j <= f - d; t[d + k++] = aux[j++]); // le reste du tableau droit
}



