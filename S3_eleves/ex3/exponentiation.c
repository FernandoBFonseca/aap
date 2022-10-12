#include "test_utils.h"
#include "../include/traces.h"
#include <stdio.h>

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data Puissance(T_data d , int n) {
	T_elt Result;
	T_elt x = d.elt; 

	// Version corrigée de l'exercice précédent

	if (n == 0) return genData(1, NULL);
		for (Result = x; n > 1; n--) {
			Result *= x;
			stats.nbOperations ++;
		}

	return genData(Result, NULL);
}

T_data Puissance_rec(T_data d , int n) {
	T_elt x = d.elt;
	T_data r;

	// Version corrigée de l'exercice précédent

	// ordre de récurrence : n 
	// cas de base : 
	if (n == 0) return genData(1, NULL);
	if (n == 1) return genData(x, NULL);

	// cas général : 
	r = Puissance_rec(d , n-1) ; 
	stats.nbOperations ++;
	return genData(x * r.elt, NULL);
}

T_data PuissanceRapide(T_data d, int n){
	T_elt Result = 1;
	T_elt x = d.elt;

	while (n > 0) {
		if ((n % 2) == 1){
			Result *= x; stats.nbOperations ++;
			n--;
		}
		x = x*x;	stats.nbOperations ++;
		n = n>>1;	// équivalent à n=n/2
	}

	return genData(Result, NULL);


}

T_data PuissanceRapide_rec(T_data d, int n){
	T_elt x = d.elt;
	T_data r;

	// ordre de récurrence : n 
	// cas de base : 
	if (n == 0) return genData(1, NULL);
	if (n == 1) return genData(x, NULL);

	// cas général :
	if (n%2) {
		// impair
		stats.nbOperations ++;
		r = PuissanceRapide_rec(genData(x*x, NULL), (n-1)/2);
		stats.nbOperations ++;
		return genData(x*r.elt, NULL);
		
	} else {
		// pair 
		stats.nbOperations ++;
		return  PuissanceRapide_rec(genData(x*x, NULL), n/2);
	}
}


