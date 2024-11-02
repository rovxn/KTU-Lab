%{
#include<stdio.h>
int lc = 0;
int cc=0;
int wc=0;
%}

%%
\n {lc++;cc++;}
[ \t]+ {cc++;}
[a-zA-Z] {cword();cc+=yyleng;}
. {cc++;}
%%
void cword(){
wc++;
}
int main(){
yylex();
printf("The line count is %d\n",lc);
printf("The word count is %d\n",wc);
printf("The character count is %d\n",cc);
return 0;
}
int yywrap(){
	return 1;
}