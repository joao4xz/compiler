#include "sint.h"

void main() {
	while(1){
		strcpy(postfix, ("Expressão pós-fixa: "));
		token = analex();
		printf("Expressão infixa: ");
		E();
		if (token != ';')
			erro();
		else {
			printf(";\n");
			printf("%s", postfix);
			printf("\nResultado: %d\n\n", pop());
		}
	}
}
