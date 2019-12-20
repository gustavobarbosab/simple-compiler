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
    return TRUE;
}

Token *proximo_token() {
    return yylex();
}

void imprime_token(Token *tok) {
    if (tok->tipo == TOK_ID)
        printf(" [tipo:%d, valor:%s, linha:%d, coluna:%d]\n", tok->tipo, tok->valorId, tok->linha, tok->coluna);
    else
        printf(" [tipo:%d, valor:%d, linha:%d, coluna:%d]\n", tok->tipo, tok->valor, tok->linha, tok->coluna);
}

int main(int argc, char **argv) {
    char *arquivo = "/home/usertqi/Documentos/compiladores/exemplo.gb";
    Token *tok;

    printf("\nAnalise Lexica da expressao: ");

    int resultadoAbertura = inicializa_arquivo(arquivo);

    if (resultadoAbertura == FALSE)
        return 0;

    tok = proximo_token();

    while (tok != NULL) {
        imprime_token(tok);
        tok = proximo_token();
    }
    return 0;
}