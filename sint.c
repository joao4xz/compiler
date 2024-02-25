#include <stdio.h>
#include <stdlib.h>
#include "analex.h"
#include "pilha.h"

int token;
void E();
void T();
void E_linha();
void T_linha();
void F();
void erro();
void reconhecer(int tok);
void erro() {
	printf("Erro no token: %d\n", token);
	printf("Erro sintatico\n");
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
			a = pop();
			b = pop();
			push(b+a);
			E_linha();
			break;
		case 45:
			printf("-");
			reconhecer('-');
			T();
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
			a = pop();
			b = pop();
			push(b*a);
			T_linha();
			break;
		case 47:
			printf("/");
			reconhecer('/');
			F();
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


void main() {
	while(1){
		token = analex();
		if (token == 0)
			exit(1);
		E();
		if (token != ';')
			erro();
		else {
			printf(";\n");
			printf("Sucesso!!\n");
			printf("Resultado: %d\n\n", pop());
		}
	}
}
