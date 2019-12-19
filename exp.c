#include "lexer.h"
#include "exp.h"

/* Define a leitura de uma string ao invés da entrada padrão */
YY_BUFFER_STATE buffer;

void inicializa_string(char *str) {
    buffer = yy_scan_string(str);
}

int inicializa_arquivo(char *nome) {
    FILE *f = fopen(nome, "r");
    if (f == NULL)
        return FALSE;
    yyin = f;
}

Token *proximo_token() {
    return yylex();
}

void imprime_token(Token *tok) {
    printf(" [tipo:%d, valor:%d, linha:%d, coluna:%d]\n", tok->tipo, tok->valor, tok->linha, tok->coluna);
}

int main(int argc, char **argv) {
    char entrada[200];
    Token *tok;

    printf("\nAnalise Lexica da expressao: ");

    fgets(entrada, 200, stdin);
    inicializa_string(entrada);
    tok = proximo_token();

    while (tok != NULL) {
        imprime_token(tok);
        tok = proximo_token();
    }
    return 0;
}