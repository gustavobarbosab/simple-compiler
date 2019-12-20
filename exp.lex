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
\+ { return token(TOK_OP, SOMA, yylineno, yyout); }
\- { return token(TOK_OP, SUB, yylineno,yyout); }
\* { return token(TOK_OP, MULT, yylineno, yyout); }
\/ { return token(TOK_OP, DIV, yylineno, yyout); }
\( { return token(TOK_ABRE_PAR, NADA, yylineno, yylineno); }
\) { return token(TOK_FECHA_PAR, NADA, yylineno, yylineno); }
\se { return token(TOK_SE, NADA, yylineno, yylineno); }
\entao { return token(TOK_ENTAO, NADA, yylineno, yylineno); }
\senao { return token(TOK_SENAO, NADA, yylineno, yylineno); }
{ID} { return tokenId(TOK_ID, yytext, yylineno, yylineno); } /*** NÃO SEI COMO RETORNAR ELE ***/
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
Token *tokenId (int tipo,
              char *valor,
              int linha,
              int coluna) {
 tok.tipo = tipo;
 tok.valorId = valor;
 tok.linha = linha;
 tok.coluna = coluna;
 return &tok;
}