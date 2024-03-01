#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analex.h"
#include "pilha.h"

int token;
char postfix[100];  
void E();
void T();
void E_linha();
void T_linha();
void F();
void erro();
void reconhecer(int tok);
void erro() {
	printf("\nErro no token: %d\n", token);
	printf("Erro sintatico na linha: %d\n", linha);
	exit(1);
}

void reconhecer(int tok) {
	if (tok == token) 
		token = analex();
	else {
		erro();
	}
}

void E() {
	T();
	E_linha();	
}

void T() {
	F();
	T_linha();
}

void E_linha() {
	switch (token) {
		case 43:
			printf("+");
			reconhecer('+');
			T();
			strcat(postfix, "+");
			a = pop();
			b = pop();
			push(b+a);
			E_linha();
			break;
		case 45:
			printf("-");
			reconhecer('-');
			T();
			strcat(postfix, "-");
			a = pop();
			b = pop();
			push(b-a);
			E_linha();
			break;
	}
}

void T_linha() {
	switch (token) {
		case 42:
			printf("*");
			reconhecer('*');
			F();
			strcat(postfix, "*");
			a = pop();
			b = pop();
			push(b*a);
			T_linha();
			break;
		case 47:
			printf("/");
			reconhecer('/');
			F();
			strcat(postfix, "/");
			a = pop();
			b = pop();
			push(b/a);
			T_linha();
			break;
	}
}

void F() {
	switch (token) {
		case NUM:
			printf("%d", tokenval);
			push(tokenval);
			snprintf(postfix + strlen(postfix), sizeof(postfix) - strlen(postfix), "%d", tokenval);
			reconhecer(NUM);
			return;
		case 40:
			printf("(");
			reconhecer('(');
			E();
			printf(")");
			reconhecer(')');	
			return;
		default: erro();
	}
}

