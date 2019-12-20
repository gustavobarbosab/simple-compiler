%{
 #include "exp.h"
%}

%option noyywrap
%option nodefault
%option lex-compat
%option outfile="lexer.c" header-file="lexer.h"

NUMERO [0-9]+
ID [a-z][a-z0-9]*

%%
{NUMERO} {return token(TOK_NUMERO, atoi(yytext), yylineno, yyleng); }
\int { return token(TOK_TYPE, INT, yylineno, yyout); }
\float { return token(TOK_TYPE, FLOAT, yylineno, yyout); }
\char { return token(TOK_TYPE, CHAR, yylineno, yyout); }
\+ { return token(TOK_OP, SOMA, yylineno, yyout); }
\- { return token(TOK_OP, SUB, yylineno,yyout); }
\* { return token(TOK_OP, MULT, yylineno, yyout); }
\/ { return token(TOK_OP, DIV, yylineno, yyout); }
\( { return token(TOK_ABRE_PAR, NADA, yylineno, yylineno); }
\) { return token(TOK_FECHA_PAR, NADA, yylineno, yylineno); }
\{ { return token(TOK_INI_BLOCO, NADA, yylineno, yylineno); }
\} { return token(TOK_FIM_BLOCO, NADA, yylineno, yylineno); }
\; { return token(TOK_PT_VIRG, NADA, yylineno, yylineno); }
\= { return token(TOK_ATRB, NADA, yylineno, yylineno); }
\se { return token(TOK_SE, NADA, yylineno, yylineno); }
\entao { return token(TOK_ENTAO, NADA, yylineno, yylineno); }
\senao { return token(TOK_SENAO, NADA, yylineno, yylineno); }
\enquanto { return token(TOK_ENQUANTO, NADA, yylineno, yylineno); }
\faca { return token(TOK_FACA, NADA, yylineno, yylineno); }
{ID} { return tokenChar(TOK_ID, yytext, yylineno, yylineno); }
\> { return token(TOK_RELOP, GT, yylineno, yylineno); }
\>= { return token(TOK_RELOP, GE, yylineno, yylineno); }
\< { return token(TOK_RELOP, LT, yylineno, yylineno); }
\<= { return token(TOK_RELOP, LE, yylineno, yylineno); }
\== { return token(TOK_RELOP, EQ, yylineno, yylineno); }
\!= { return token(TOK_RELOP, NE, yylineno, yylineno); }
[ \t\n]+ { }
. { return token(TOK_ERRO, NADA, yylineno, yylineno); }
%%

Token tok;
Token *token (int tipo,
              int valor,
              int linha,
              int coluna) {
 tok.tipo = tipo;
 tok.valor = valor;
 tok.linha = linha;
 tok.coluna = coluna;
 return &tok;
}
Token *tokenChar (int tipo,
              char *valor,
              int linha,
              int coluna) {
 tok.tipo = tipo;
 tok.valorId = valor;
 tok.linha = linha;
 tok.coluna = coluna;
 return &tok;
}