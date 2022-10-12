#include<stdio.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

int Partitionnement (T_elt t [], int g, int d); 

int comparer(T_elt e1, T_elt e2) {
	
	stats.nbComparisons++; 
	return e1-e2; 
}

void echanger(T_elt t[], int i1, int i2) {
	
	T_elt aux = t[i1];
	t[i1] = t[i2];
	t[i2] = aux;

}


T_data quickSort(T_data d, int n){

	T_elt * A = d.pElt; 

	Tri_rapide(A,0,n-1);

	return genData(0, A);
}

void Tri_rapide( T_elt t[], int debut, int fin) {

	stats.nbComparisons++;
	if(fin>debut){

		//Amélioration: Pivote à chaque itération
		//pour éviter le cas de la dégénérescence
		echanger(t, debut + rand() % (fin - debut), fin);
		
		int pivot_loc = Partitionnement(t, debut, fin);
		Tri_rapide(t, debut, pivot_loc-1);
		Tri_rapide(t, pivot_loc+1, fin);
	}	
}





int Partitionnement (T_elt t [], int g, int d){ 
	int pg=g , pd=d-1; // On utilise g et d comme « pointeurs » qui se déplacent
	// On choisit le dernier élément comme pivot

	while (pg<pd) {
		// On déplace pg et pd jusqu’à trouver des valeurs incohérentes % pivot
		stats.nbComparisons++;
		while ( (pg<pd) &&  (comparer(t[pg],t[d]) <=0) ) {pg++ ;	stats.nbComparisons ++;}
		while ( (pg<pd) && (comparer(t[pd],t[d])>0) ) {pd-- ; stats.nbComparisons ++;}

		// Comment compter correctement ? On utilise une fonction de comparaison...
		if (pg < pd) {
			stats.nbOperations++;
			echanger(t,pg,pd); 
			pg++ ; pd-- ; 
		}
	}
	stats.nbComparisons ++;
	if (comparer(t[pg],t[d]) <= 0) pg++ ;  
	
	stats.nbOperations+=3;
	echanger(t, pg, d) ;

	return pg ; 
}
