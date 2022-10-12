#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//#define CLEAR2CONTINUE
#include "../include/traces.h" 

void test_aveCesar(void); 
void test_dyhCesar(void);
void test_cesar(void); 
void test_rot13(void); 

char * aveCesar(const char *s);
char * dyhCesar(const char *s);
char * cesar (const char * s, int decalage);

#define rot13(s) "[Macro-fonction rot13() à modifier]"	// TODO : rot13() retourne le résultat du chiffrement de la chaîne de caractères transmise en paramètre en appliquant un décalage de 13 rangs

int main (int argc , char * argv []){

	CLRSCR();
	WHOAMI(); 
	
	test_aveCesar(); 
	test_dyhCesar(); 
	test_cesar();
	test_rot13(); 

	// TODO : Commande shell de chiffrement-déchiffrement
 
	return 0;
}

void test_aveCesar (void) {
	PRINT_FN(); NL();
	printf ("%s\n", aveCesar ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf ("%s\n", aveCesar ("TU QUOQUE MI FILI"));
	printf ("%s\n", aveCesar ("VENI VIDI VICI"));
	printf ("%s\n", aveCesar ("XIBX GXZQX BPQ"));
	printf ("%s\n", aveCesar ("PF SFP MXZBJ MXOX YBIIRJ"));
}

void test_dyhCesar (void) {
	PRINT_FN(); NL();
	printf ("%s\n", dyhCesar ("DEFGHIJKLMNOPQRSTUVWXYZABC"));
	printf ("%s\n", dyhCesar ("VDWRU \nDUHSR \nWHQHW \nRSHUD \nURWDV"));
	printf ("%s\n", dyhCesar ("GHPR GHV PDXA GHV PRWV"));
	printf ("%s\n", dyhCesar ("YDH YLFWLV"));
}

void test_cesar(void) {
	PRINT_FN(); NL();
	printf ("%s\n", cesar ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3));
	printf ("%s\n", cesar ("TU QUOQUE MI FILI", 3));
	printf ("%s\n", cesar ("VENI VIDI VICI", 3));
	printf ("%s\n", cesar ("XIBX GXZQX BPQ", 3));
	printf ("%s\n", cesar ("PF SFP MXZBJ MXOX YBIIRJ", 3));
	printf ("\n");
	printf ("%s\n", cesar ("DEFGHIJKLMNOPQRSTUVWXYZABC", -3));
	printf ("%s\n", cesar ("VDWRU \nDUHSR \nWHQHW \nRSHUD \nURWDV", -3));
	printf ("%s\n", cesar ("GHPR GHV PDXA GHV PRWV", -3));
	printf ("%s\n", cesar ("YDH YLFWLV", -3));
}

void test_rot13(void) {
	char * indication = "P'rfg fba svyf"; 
	char * decoded; 

	PRINT_FN(); NL();

	printf("Un homme vous montre un portrait et dit : « Je n’ai pas de frère ni de sœur, mais le père de cet homme est le fils de mon père. » Qui est représenté par le portrait ?\n");
	decoded = rot13(indication); 
	printf("La réponse est : %s\n",decoded);
	printf("rot13(rot13(%s)) = %s\n",indication, rot13(rot13(indication)));
}

char * aveCesar(const char *s) {
	// TODO : aveCesar() retourne le résultat du chiffrement 
	// de la chaîne de caractères transmise en paramètre
	// Consigne : développer cette fonction en utilisant les fonctions 
	// de la librairie standard, décrites dans string.h et ctype.h 

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	return "[Fonction aveCesar() à modifier]";
}

char * dyhCesar(const char *s) {
	// TODO : dyhCesar() retourne le résultat du déchiffrement 
	// de la chaîne de caractères transmise en paramètre
	// Consigne : développer cette fonction SANS UTILISER les fonctions 
	// de la librairie standard, décrites dans string.h et ctype.h 

	TOUCH_HERE("Ben là, c'est à vous ! \n");
	
	return "[Fonction dyhCesar() à modifier]";
}

char * cesar (const char * s, int decalage) {
	// TODO : cesar() retourne le résultat du chiffrement 
	// de la chaîne de caractères transmise en paramètre 
	// en appliquant le décalage passé en paramètre

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	return "[Fonction cesar() à modifier]";
}	

