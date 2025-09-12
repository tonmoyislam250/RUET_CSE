%{
#include "condition.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%%

"int"           { return INT; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"printf"        { return PRINTF; }

[a-zA-Z_][a-zA-Z0-9_]*  { return IDENTIFIER; }
[0-9]+          { return NUMBER; }

"<"             { return LT; }
">"             { return GT; }
"=="            { return EQ; }
"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"++"            { return INCREMENT; }
"--"            { return DECREMENT; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

\"[^"]*\"       { return STRING; }

[ \t\n]+        { /* ignore whitespace */ }
"//".*          { /* ignore single-line comments */ }

.               { printf("Unexpected character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
