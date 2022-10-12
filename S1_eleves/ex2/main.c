#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// sélection de la fonction de lecture
#ifdef USE_GETCHAR
	#define READ_CAR() getchar()
#else
	#define READ_CAR() fgetc(stdin)
#endif

int main(int argc, char ** argv) {

	char c = "A";

	CLRSCR();
	WHOAMI(); 

	// Affichage de la fonction de lecture utilisée
	#ifdef USE_GETCHAR
		printf("Mode lecture : getchar\n");
	#else 
		printf("Mode lecture : fgetc\n");
	#endif

	printf("Saisir des caractères au clavier (Ctrl+D) pour terminer\n");
	
	while( c != EOF){
		c = getchar();
		printf("Get : .%c.\n", c);
	}

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	// correction


	ENTER2CONTINUE();

	return 0;
}
