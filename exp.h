// geral
#define TRUE 1
#define FALSE 0
#define NADA -1

// nome de token
#define TOK_ERRO 9999
#define TOK_NUMERO 0
#define TOK_ID 1
#define TOK_OP 2
#define TOK_RELOP 3
#define TOK_SE 4
#define TOK_ENTAO 5
#define TOK_SENAO 6
#define TOK_ENQUANTO 7
#define TOK_FACA 8
#define TOK_ATRB 9
#define TOK_ARTOP 10
#define TOK_ABRE_PAR 12
#define TOK_FECHA_PAR 13
#define TOK_INI_BLOCO 14
#define TOK_FIM_BLOCO 15
#define TOK_PT_VIRG 16
#define TOK_TYPE 17

// operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

// operadores relacionais
#define LE 0
#define NE 1
#define LT 2
#define EQ 3
#define GE 4
#define GT 5

// tipos definidos
#define INT 1
#define FLOAT 2
#define CHAR 3

// estrutura que representa um token
typedef struct {
    int tipo;
    int valor;
    int linha;
    int coluna;
    char *valorId;
} Token;

// funcao para criar um token
extern Token *token();
extern Token *tokenChar();

// funcao principal do analisador lexico
extern Token *yylex();
