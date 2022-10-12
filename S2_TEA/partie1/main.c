#include <stdio.h>

#include "../include/traces.h" 
#include "../include/check.h"

#include "base_change.h"

int main(int argc, char ** argv) {
	
	CHECK_IF(argc, 1, "ERROR: Wrong Usage!!\nPlease insert a correct input:\n ./*.exe 'value' 'new base'\n");

	int decimal = atoi(argv[1]);
	int new_base;
	if(argv[2] == NULL) new_base = 2;
	else new_base = atoi(argv[2]);

	printf("Changing %d in base 10 to base %d:\n\n", decimal, new_base);
	printf("Not using stacks (Inverted Order!): ");
	base_change_basic(decimal, new_base);
	NL();
	printf("Using stacks (Correct Order!):      ");
	base_change_stack(decimal, new_base);
	NL();
 	
	return 0;
}







