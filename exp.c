#include "lexer.h"
#include "exp.h"

/* Define a leitura de uma string ao invés da entrada padrão */
YY_BUFFER_STATE buffer;

void inicializa(char *str) {
    buffer = yy_scan_string(str);
}

Token *proximo_token() {
    return yylex();
}

void imprime_token(Token *tok) {
    printf("<%d-",tok->tipo);
    printf("%d> ",tok->valor);
}

int main(int argc, char **argv) {
    char entrada[200];
    Token *tok;

    printf("\nAnalise Lexica da expressao: ");

    fgets(entrada, 200, stdin);
    inicializa(entrada);
    tok = proximo_token();

    while (tok != NULL) {
        imprime_token(tok);
        tok = proximo_token();
    }
    return 0;
}