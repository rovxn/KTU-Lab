%{
#include<stdio.h>
%}
LETTER [a-zA-Z]
DIGIT [0-9]
IDENTIFIER ({LETTER}({LETTER}|{DIGIT})*)
NUMBER ({DIGIT}({DIGIT})*)
OPERATOR [+-/*<>=]
SPECS [(){};"]
%%
"if" {printf("keyword is if\n");}
"while" {printf("keyword is while\n");}
"for" {printf("keyword is for\n");}
"void" {printf("keyword is void\n");}
"main" {printf("keyword is main\n");}
"printf" {printf("keyword is printf");}
"int" {printf("keyword is int");}
{NUMBER} {printf("The Digit is %s\n",yytext);}
{IDENTIFIER} {printf("The IDENTIFIER is %s\n",yytext);}
{OPERATOR} {printf("The operator is %s\n",yytext);}
{SPECS} {printf("The operator is %s\n",yytext);}
%%
int main(){
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}