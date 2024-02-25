#include "analex.h"

void main() {
	int token;
	token = analex();
	while (token) {
		printf("- %d => %d \n", token, tokenval);
		token = analex();
	}
}
