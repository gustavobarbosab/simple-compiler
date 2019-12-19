%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"
%{
 #include "exp.h"
%}

DIGITO [0-9]+
COMMENT_LINE "//".*
COMMENT_MULT_LINE [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]

%%
[[:space:]] { }
{COMMENT_LINE} { }
{COMMENT_MULT_LINE} { }
{DIGITO} { return token(TOK_DIGITO, atoi(yytext)); }
\+ { return token(TOK_OP, SOMA); }
- { return token(TOK_OP, SUB); }
\* { return token(TOK_OP, MULT); }
\/ { return token(TOK_OP, DIV); }
\( { return token(TOK_PONT, PAR_ESQ); }
\) { return token(TOK_PONT, PAR_DIR); }
se { return token(TOK_CONDICAO, SE); }

. { return token(TOK_ERRO, 0); }
%%

Token tok;
Token *token (int tipo, int valor) {
 tok.tipo = tipo;
 tok.valor = valor;
 return &tok;
}