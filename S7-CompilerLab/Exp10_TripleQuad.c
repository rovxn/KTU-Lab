#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>


char tac[10][30],inp[20];
int tempCount=1;
char tempvar[3];
int len;

int curr=0;
int t_ind=0;
int if_t=0;
//int isOperator()

int findHighest(){

	int maxm=0;
	int ind=0;
	
	for(int i=1;i<len;i+=2){
//	printf("inp[i]=%c\n",inp[i]);
		if(inp[i]=='('){
			return i;
		}
		else if(inp[i]=='*'){
			if(maxm<2){
				maxm=2;
				ind=i;
			}	
		}
		else if(inp[i]=='/'){
			if(maxm<2){
				maxm=2;
				ind=i;
			}
		}
		else if(inp[i]=='+'){
			if(maxm<1){
				maxm=1;
				ind=i;
			}
		}
		else if(inp[i]=='-'){
			if(maxm<1){
				maxm=1;
				ind=i;
			}
		}
		
	}
//	printf("Return\n");
	return ind;	
}

void ShiftLeft(int left,int right,int temp){
	
	
	//printf("Temp = %d\n");
	char t[2];
	sprintf(t,"%d",temp); // int to string 
	inp[left]=t[0]; // t[0] contain value t[1] contain '\0'
	left++;
	right++;
	while(right<len){
		inp[left++]=inp[right++];
	}
	inp[right]='\n';
	

}
int findOp(int i)
{
	for(int j=0;j<strlen(tac[i]);j++)
	{
		if(tac[i][j]=='-' || tac[i][j]=='+' || tac[i][j]=='*' || tac[i][j]=='/')
		{
			return j;
		}
	}
	return 0;
}

int findArg1(int i)
{
	for(int j=0;j<strlen(tac[i]);j++)
	{
		if(tac[i][j]=='=')
		{
			int ind=j+2; // skipping j+1 bcz it is whitespace
			if(tac[i][ind]=='t')
			if_t=1; 
			return ind;
		}
	}
	return 0;
}
int findArg2(int i)
{
	for(int j=0;j<strlen(tac[i]);j++)
	{
		if(tac[i][j]=='-' || tac[i][j]=='+' || tac[i][j]=='*' || tac[i][j]=='/')
		{
			int ind=j+1;
			if(tac[i][ind]=='t')
			if_t=1; 
			return ind;
		}
	}
	return 0;
}
int findRes(int i)
{
			
			if(tac[i][0]=='t')
			if_t=1; 
			return 0;
}
void quadrable()
{
	int ind=0;
	printf("op\t\t\targ1\t\t\targ2\t\t\tres\n");
	for(int i=0;i<t_ind;i++)
	{
		ind=findOp(i);
		printf("%c\t\t\t",tac[i][ind]);
		ind=findArg1(i);
		if(if_t==1)
			printf("%c%c\t\t\t",tac[i][ind],tac[i][ind+1]);
		else
			printf("%c\t\t\t",tac[i][ind]);
		if_t=0;
		ind=findArg2(i);
		if(if_t==1)
			printf("%c%c\t\t\t",tac[i][ind],tac[i][ind+1]);
		else
			printf("%c\t\t\t",tac[i][ind]);
		if_t=0;
		ind=findRes(i);
		if(if_t==1)
			printf("%c%c\t\t\t",tac[i][ind],tac[i][ind+1]);
		else
			printf("%c\t\t\t",tac[i][ind]);
		if_t=0;
		printf("\n");
	}
}

void triple()
{	int ind=0;
	printf("ind\t\t\top\t\t\targ1\t\t\targ2\n");
	for(int i=0;i<t_ind;i++)
	{
		printf("%d\t\t\t",i+1);
	
		
		
		
		ind=findOp(i);
		printf("%c\t\t\t",tac[i][ind]);
		ind=findArg1(i);
		if(if_t==1)
		{
			
			printf("%c\t\t\t",tac[i][ind+1]);
		}
		else
			printf("%c\t\t\t",tac[i][ind]);
		if_t=0;
		ind=findArg2(i);
		if(if_t==1)
		{
			
			printf("%c\t\t\t",tac[i][ind+1]);
		}
		else
			printf("%c\t\t\t",tac[i][ind]);
		if_t=0;
		
		printf("\n");
	}
}
void main()
{
	printf("Enter the expression\n");
	scanf("%s",inp);
	
	len=strlen(inp);
	
	
	int ind;
	char op1,op2,op;
	char f[3],s[3];
	while(1){
		ind=findHighest();
		//printf("Ind = %d\n",ind);
		op1=inp[ind-1];
		op2=inp[ind+1];
		op=inp[ind];
		//printf("op1 = %c\n",op1);
		
			if(isdigit(op1)){
				sprintf(f,"t%c",op1);	
			}
			else{
				sprintf(f,"%c",op1);
			}
			
			if(isdigit(op2)){
				sprintf(s,"t%c",op2);	
			}
			else{
				sprintf(s,"%c",op2);  
			}
		
		sprintf(tempvar,"t%d",tempCount++); // tempVar = t1 or t2 ... 
		sprintf(tac[t_ind++],"%s = %s%c%s",tempvar,f,op,s);
		//printf("TAC\n");
		
		/*
		for(int i=0;i<t_ind;i++){
		printf("%s\n",tac[i]);
		}
		*/
		ShiftLeft(ind-1,ind+1,tempCount-1);
		//printf("New inp after left %s\n",inp);
		len=len-2;
		//printf("New len = %d\n",len);
		if(len==1)
			break;
	}
	
	// tac contain answer
	for(int i=0;i<t_ind;i++){
		printf("%s\n",tac[i]);
	}
	
	printf("\nQuadtruple: \n\n");
	quadrable();
	printf("\nTriple: \n\n");
	triple();
	
}