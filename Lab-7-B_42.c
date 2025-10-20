/*42. Write a program to convert infix notation to prefix notation using stack.*/
#include<stdio.h>
#include<string.h>
int top;
int rank=0;
char polish[]="";
char rev_polish[100]; 
char string[100];
char rev_string[100];
char stack[100];
char temp;
char next;
void push(char ch){
	if(top>=100){
		printf("Stack OverFlow");
		return;
	}
	stack[++top]=ch;
}
char pop(){
	if(top==-1){
		printf("Stack UnderFlow");
		return;
	}
	return stack[top--];
}
int g(char ch){
	if(ch=='+'||ch=='-'){
		return 1;
	}
	if(ch=='*'||ch=='/'){
		return 3;
	}
	if(ch=='^'){
		return 6;
	}
	if(ch=='('){
		return 0;
	}
	else{
		return 8;
	}
}
int f(char ch){
	if(ch=='+'||ch=='-'){
		return 2;
	}
	if(ch=='*'||ch=='/'){
		return 4;
	}
	if(ch=='^'){
		return 5;
	}
	if(ch=='('){
		return 9;
	}
	if(ch==')'){
		return 0;
	}
	else{
		return 7;
	}
}
int r(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
		return -1;
	}
	else{
		return 1;
	}
}
void revpol(){
	top=-1;
	rank=0;
	push('(');
	int i=0,j=0;
	next = rev_string[i];
	while(next != '\0'){
		if(top<0){
			printf("INVALID 1");
			return;
		}
		while(g(stack[top])>f(next)){
			temp=pop();
			polish[j++] = temp;
			rank = rank + r(temp);
			if(rank<1){
				printf("INVALID 2");
				return;
			}
		}
			if(g(stack[top])!=f(next)){
				push(next);
			}
			else{
				pop();
			}
		next = rev_string[++i];
	}
	if(top!=-1 || rank != 1){
		printf("INVALID 3\n");
	}
	else{
		printf("\vVALID\n");	
	}
		for(i=strlen(polish)-1;i>=0;i--){
			rev_polish[strlen(polish)-i-1] = polish[i];
		}
		printf("top:%d\nrank=%d",top,rank);
		printf("\nPOLISH:%s",polish);
		printf("\nREV_POLISH:%s",rev_polish);
		printf("\nstack:");
		for(i=top;i>=0;i--){
			printf("%c",stack[i]);
		}
}
void main(){
	int k;
	printf("Enter Infix:");
	scanf("%s",string);
	rank=strlen(string);
	for(k=rank-1;k>=0;k--){
		if(string[k]=='('){
			rev_string[rank-k-1] = ')';
		}
		else if(string[k]==')'){
			rev_string[rank-k-1] = '(';
		}
		else{
			rev_string[rank-k-1] = string[k];	
		}
	}
	rev_string[rank]=')';
	printf("String:%s",rev_string); 
	revpol();
}
