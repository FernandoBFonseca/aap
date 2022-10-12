#include <assert.h> // assert

#include "../include/check.h" 

#include "../include/traces.h" 

#include "list_v2.h"
#include "genPNG.h" 


void generatePNG(const T_list l, const char * filename){

	char fNameOutput[50], cmd[100];

	sprintf(fNameOutput, "%s.dot", filename);

	FILE *fpTemplate, *fpOutput;

	fpTemplate = fopen("template.dot", "r"); 
	if(fpTemplate == NULL){
		fpTemplate = fopen("partie3/template.dot", "r"); 
		sprintf(fNameOutput, "partie3/%s.dot", filename);
	}
		
	fpOutput = fopen(fNameOutput, "w");

	char ch = fgetc(fpTemplate);
    while (ch != EOF){
        fputc(ch, fpOutput);
        ch = fgetc(fpTemplate);
    }

	int i = 1;
	T_list aux = l;

	while(aux != NULL){

		if(aux->pNext != NULL){
			fprintf(fpOutput, "\"ID_%04i\" [label = \"{<elt> %s | <next> }\"];\n",i,toString(aux->data));
			fprintf(fpOutput, "\"ID_%04i\" : next -> \"ID_%04i\";\n",i,i+1);
		}
		else{
			fprintf(fpOutput, "\"ID_%04i\" [label = \"{<elt> %s | <next> NULL}\"];\n}",i,toString(aux->data));	
		}
		i++;
		aux = aux->pNext;
	}

	fclose(fpTemplate); 
	fclose(fpOutput); 

	sprintf(cmd, "dot %s -T png -o %s.png", fNameOutput, filename);

	printf("Generating PNG:\n");
	printf(">> %s\n", cmd);
	system(cmd);


	return;

}

T_list exempleList(){
	T_list l = NULL;

	l = tailAddNodeIte("AAP", l);
	l = tailAddNodeIte("=", l);
	l = tailAddNodeIte("Algorithmique", l);
	l = tailAddNodeIte("Avancée", l);
	l = tailAddNodeIte("et", l);
	l = tailAddNodeIte("Programmation", l);
	
	return l;
	
}
T_list genList(){

	T_list l = NULL;
	int i = 0;
	char **inputs;
	inputs = (char**) malloc(50*sizeof(char*));
	char input[50];
	
	while(1){
		
		printf("Input the %d° element of the list: (write q! to finish the list)", i+1);
		getchar();
		scanf("%[^\n]", input);

		if(strcmp("q!", input) == 0) break;
		else {
			inputs[i] = (char*) malloc(strlen(input)*sizeof(char));
			strcpy(inputs[i], input);
			
			l = tailAddNodeIte(inputs[i++], l);
		}
		
	}

	free(inputs);
	
	return l;


}