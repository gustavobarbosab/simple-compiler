// booleano
#define TRUE 1
#define FALSE 0

// nome de token
#define TOK_DIGITO 0
#define TOK_OP 1
#define TOK_PONT 2
#define TOK_CONDICAO 3
#define TOK_ERRO 9999

// operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

// pontuacao
#define PAR_ESQ 0
#define PAR_DIR 1

// condicional
#define SE 0

// estrutura que representa um token
typedef struct {
    int tipo;
    int valor;
} Token;

// funcao para criar um token
extern Token *token();

// funcao principal do analisador lexico
extern Token *yylex();