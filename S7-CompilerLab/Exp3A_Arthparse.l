Lex Code

%{
    #include "y.tab.h"
%}

token id num op

%%
[a-zA-Z_][a-zA-Z_0-9]* return id;
[0-9]+(\.[0-9]*)?      return num;
[+/*]                  return op;
.                      return yytext[0];
\n                     return 0;
%%

int yywrap(){
return 1;
}


YACC Code

%{
    #include<stdio.h>
    int valid=1;

    // Function declarations
    int yylex();           
    void yyerror(const char *s); 
%}

%token num id op

%%

start : statement ';'      { /* Handles a statement followed by a semicolon */ }
      | statement ';' start { /* Multiple statements separated by semicolons */ }
      ;

statement : id '=' expression    { /* Assignment statement */ }
          | expression           { /* Just an expression */ }
          ;

expression : term op expression  { /* Recursive case for operations like b + c */ }
           | term                { /* Single term, e.g., a number or identifier */ }
           ;

term : id                        { /* Identifier, like a variable */ }
     | num                       { /* Number, like a constant */ }
     | '-' term                  { /* Unary minus for negation */ }
     | '(' expression ')'         { /* Parenthesized expression */ }
     ;

%%

void yyerror(const char *s) {
    valid = 0;
    printf("\nInvalid expression!\n");
}

int main() {
    printf("\nEnter the expression:\n");
    yyparse();
    if(valid) {
        printf("\nValid expression!\n");
    }
    return 0;
}