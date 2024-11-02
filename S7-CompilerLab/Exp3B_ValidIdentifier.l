Lex Code

%{
    #include "y.tab.h"
%}


%%
[a-zA-Z_][a-zA-Z_0-9]* return letter;
[0-9] return digit;
. return yytext[0];
\n return 0;
%%

int yywrap() {
    return 1;
}

YACC Code

%{
    #include<stdio.h>
    int valid=1;
%}
%token digit letter
%%
    start: letter s
    s: letter s
    | digit s
    |
    ;
%%
int yyerror()
{
    valid=0;
    printf("Invalid variable!\n");
    return 0;
}
int main()
{
    printf("Enter the variable:\n");
    yyparse();
    if(valid)
    {
        printf("Valid variable!\n");
    }
}