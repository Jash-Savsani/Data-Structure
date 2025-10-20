/*41. Write a program to convert infix notation to postfix notation using stack.*/
#include<stdio.h>
#include<string.h>
int top;
int rank=0;
char polish[]=""; 
char string[100];
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
		return 2;
	}
	if(ch=='*'||ch=='/'){
		return 4;
	}
	if(ch=='^'){
		return 5;
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
		return 1;
	}
	if(ch=='*'||ch=='/'){
		return 3;
	}
	if(ch=='^'){
		return 6;
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
	next = string[i];
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
		next = string[++i];
	}
	if(top!=-1 || rank != 1){
		printf("INVALID 3\n");
	}
	else{
		printf("VALID\n");	
	}
		printf("top:%d\nrank=%d",top,rank);
		printf("\nPOLISH:%s",polish);
		printf("\nstack:");
		for(i=top;i>=0;i--){
			printf("%c",stack[i]);
		}
}
void main(){
	printf("Enter Infix:");
	scanf("%s",string);
	rank=strlen(string); 
	string[rank]=')';
	printf("String:%s",string); 
	revpol();
}
