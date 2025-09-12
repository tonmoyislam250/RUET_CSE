%{
#include <stdio.h>
void yyerror(char *s);
int yylex();
%}

%token NUM ADD SUB MULT ID ASSIGN
%start cal


%%
cal: assignment;

assignment: ID ASSIGN exp
          | exp
          ;

exp: exp ADD NUM
    |exp SUB NUM
    |exp MULT NUM
    |ID
    |NUM
    ;

%%

int main(){
    yyparse();
    printf("Parsing Finished\n");
}

void yyerror(char *s){
    fprintf(stderr, "error:%s", s);
}