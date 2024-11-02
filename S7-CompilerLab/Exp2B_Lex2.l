%{
#include<stdio.h>
int vc = 0;
int cc=0;
%}

%%
[aAeEiIoOuU] {vc++;}
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {cc++;}
. {}
%%

int main(){
yylex();
printf("The vowel count is %d\n",vc);
printf("The character count is %d\n",cc);
return 0;
}
int yywrap(){
	return 1;
}