#include <stdio.h>
#include <ctype.h>

#define NUM 256

int tokenval;
int linha = 1;

int analex() {
    int ch;
    tokenval = -1;
    ch = getchar();

    while (ch == ' ' || ch == '\t' || ch=='\n') {
        if(ch == '\n') 
            linha++;
        ch = getchar();
    }

    if(ch == '+')
        return '+';

    if(ch == '-')
        return '-';

    if(ch == '*')
        return '*';

    if(ch == '/')
        return '/';

    if(ch == '(')
        return '(';

    if(ch == ')')
        return ')';

    if(ch == ';')
        return ';';
	
    if (isdigit(ch)) {
        tokenval = ch - '0';
        ch = getchar();

        while(isdigit(ch)) {
            tokenval = tokenval * 10 + ch - '0';
            ch = getchar();
        }
        ungetc(ch, stdin);
        return NUM;
    }

    if(ch == EOF)
        exit(1);
	printf("Erro lexico na linha: %d", linha);
	exit(1);
}
