// geral
#define TRUE 1
#define FALSE 0
#define NADA -1

// nome de token
#define TOK_ERRO 9999
#define TOK_NUMERO 0
#define TOK_ID 1
#define TOK_OP 2
#define TOK_PONT 3
#define TOK_RELOP 4
#define TOK_SE 5
#define TOK_ENTAO 6
#define TOK_SENAO 7
#define TOK_ATRBCAO 8

// operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

// pontuacao
#define PT_VIRG 0
#define PAR_ESQ 1
#define PAR_DIR 2
#define CHAVE_ESQ 3
#define CHAVE_DIR 4

// operadores relacionais
#define LE 0
#define NE 1
#define LT 2
#define EQ 3
#define GE 4
#define GT 5

// estrutura que representa um token
typedef struct {
    int tipo;
    int valor;
    int linha;
    int coluna;
} Token;

// funcao para criar um token
extern Token *token();

// funcao principal do analisador lexico
extern Token *yylex();

/*
 * Inicio
 Sc ← ε-closure( s0)
 c ← prox_char()
 enquanto ( c ≠ EOF ) faça
 Sp ← ε-closure( move(Sc , c) )
 c ← prox_char()
 Sc ← Sp
 fim enquanto
 se ( final(Sc ) ) então retorna 1
 senão retorna 0
Fim
 * */