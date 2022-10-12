#include <stdio.h>

#define INWORD 1
#define OUTWORD 0
//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#define MAXTAB 26

#define STEP_1 1
#define STEP_2 2
#define STEP_3 3

void etape1(void); 
void etape2(void); 
void etape3(void);

int main(int argc, char ** argv) {
	int step=STEP_1; 

	CLRSCR();
	WHOAMI(); 

	// TODO: Cas d'étude : tout est écrit dans la trame de séance 
	// https://docs.google.com/document/d/1ELzc5StntLb2ZZqzKZY8cYReMCfd_tj9WXfu6TVKX7Q/edit?usp=sharing

	// TOUCH_HERE("Ben là, c'est à vous ! Liberté totale ! \n");
	// PROMPT("Les fichiers d'exemple sont dans le sous-répertoire extraits\n");

	if (argc>1) step = atoi(argv[1]);
	
	switch(step){
		case STEP_1 :
			printf("Etape 1\n");	 
			etape1();
		break;
		case STEP_2 : 
			printf("Etape 2\n");
			etape2();
		break;
		case STEP_3 : 
		default :
			printf("Etape 3\n");
			etape3();
	}


	return 0;
}

void etape1(void) {
	/////////////////////////////////////////////////////////////////////////
	// Etape 1 : Compléter l’exemple ci-dessus de façon à 
	// comptabiliser les caractères, 
	// ainsi que les lignes tapées au clavier par l’utilisateur.
	/////////////////////////////////////////////////////////////////////////

	char c ; 
	int counter_char = 0;
	int counter_line = 0;
	printf("Saisir des caractères au clavier (Ctrl+D) pour terminer\n");

	while ( ( c = getchar() ) != EOF) {
		
		if( c == '\n') counter_line++;
		counter_char++;
		printf("Caractère lu : '%c'\n",c);

	}

	printf("Number of characters: %d\n", counter_char);
	printf("Number of lines: %d\n", counter_line);


}

void etape2(void) {
	/////////////////////////////////////////////////////////////////////////
	// De façon à ne pas trop compliquer les traitements, 
	// on considérera qu’un mot est une séquence de caractères
	// encadrée de séparateurs et dans un premier temps, 
	// seuls trois séparateurs seront pris en compte : 
	// le saut de ligne, l’espace et le caractère de tabulation ('\t' ).
	// Modifier le programme précédent de manière à ce qu’il compte 
	// également les mots du texte tapé au clavier, en gardant à l’esprit
	// qu’il ne faut pas modifier le nombre de mots lorsqu’on lit 
	// une séquence de séparateurs.
	// Utiliser la structure de contrôle switch
	/////////////////////////////////////////////////////////////////////////

	char c ; 
	int counter_word = 0;
	int counter_char = 0;
	int counter_line = 0;
	int word_begin = OUTWORD;

	printf("Saisir des caractères au clavier (Ctrl+D) pour terminer\n");

	while ( ( c = getchar() ) != EOF) {

		printf("Caractère lu : '%c'\n",c);

		counter_char++;
		if( c == '\n') counter_line++;

		if(c == ' ' || c == '\n' || c == '\t'){
			if (word_begin){
				counter_word++;
				word_begin = OUTWORD;
			}
		}
		else word_begin = INWORD;
	}

	printf("Number of characters: %d\n", counter_char);
	printf("Number of lines: %d\n", counter_line);
	printf("Number of words: %d\n", counter_word);

}

void etape3(void) {
	/////////////////////////////////////////////////////////////////////////
	// Compléter le programme précédent de façon à afficher 
	// en plus des résultats précédents : 
	// le nombre total de caractères alphabétiques,
	// un tableau présentant le nombre d’occurrences 
	// de chaque caractère alphabétique, ainsi que sa fréquence 
	// (rapport entre le nombre d’occurrences d’un caractère alphabétique 
	// sur le nombre total de caractères alphabétiques).
	/////////////////////////////////////////////////////////////////////////


	char c ; 
	int counter_word = 0;
	int counter_char = 0;
	int counter_line = 0;
	int word_begin = OUTWORD;
	int count_letters[26] = {0};
	printf("Saisir des caractères au clavier (Ctrl+D) pour terminer\n");

	while ( ( c = getchar() ) != EOF) {

		printf("Caractère lu : '%c'\n",c);
		
		counter_char++;
		if( c == '\n') counter_line++;

		if(c == ' ' || c == '\n' || c == '\t'){
			if (word_begin){
				counter_word++;
				word_begin = OUTWORD;
			}
		}
		else word_begin = INWORD;

		if(c >= 'a' && c < 'z') count_letters[c-'a']++;
		else if(c >= 'A'  && c <= 'Z') count_letters[c-'A']++;
	}

	printf("Number of characters: %d\n", counter_char);
	printf("Number of lines: %d\n", counter_line);
	printf("Number of words: %d\n", counter_word);
	for(int i=0; i<26; i++){
		printf("| %c | %d |\n", i+'A', count_letters[i]);
	}

}