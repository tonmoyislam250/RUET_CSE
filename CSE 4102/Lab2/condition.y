%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token INT IDENTIFIER NUMBER
%token IF ELSE WHILE
%token PRINTF
%token LT EQ GT
%token ASSIGN PLUS MINUS MULT DIV
%token SEMICOLON COMMA
%token LPAREN RPAREN LBRACE RBRACE
%token STRING
%token INCREMENT DECREMENT

%left LT GT EQ
%left PLUS MINUS
%left MULT DIV

%%

program:
    statement_list
    ;

statement_list:
    statement
    | statement_list statement
    ;

statement:
    declaration
    | assignment
    | if_statement
    | while_statement
    | printf_statement
    | expression_statement
    ;

declaration:
    INT IDENTIFIER ASSIGN expression SEMICOLON
    ;

assignment:
    IDENTIFIER ASSIGN expression SEMICOLON
    ;

if_statement:
    IF LPAREN condition RPAREN LBRACE statement_list RBRACE
    | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE if_statement
    | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
    ;

while_statement:
    WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE
    ;

printf_statement:
    PRINTF LPAREN STRING RPAREN SEMICOLON
    | PRINTF LPAREN STRING COMMA expression RPAREN SEMICOLON
    ;

expression_statement:
    expression SEMICOLON
    ;

condition:
    expression LT expression
    | expression GT expression
    | expression EQ expression
    ;

expression:
    IDENTIFIER
    | NUMBER
    | expression PLUS expression
    | expression MINUS expression
    | expression MULT expression
    | expression DIV expression
    | IDENTIFIER INCREMENT
    | IDENTIFIER DECREMENT
    | LPAREN expression RPAREN
    ;

%%

int main(){
    yyparse();
    printf("Timestamp: %s %s Parsing Finished\n", __DATE__, __TIME__);
}

void yyerror(const char *s){
    printf("Timestamp: %s %s\n error: %s\n", __DATE__, __TIME__, s);
}