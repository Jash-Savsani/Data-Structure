/*38. Removing starts from a string Problem 
You are given a string s, which contains stars *. In one operation, you can: 
Choose a star in s. Remove the closest non-star character to its left, as well as 
remove the star itself. Return the string after all stars have been removed. */ 	
#include<stdio.h>
#include<string.h>
int TOP=-1;
int n=50;//size of stack
char stack[50];
void PUSH(char ch){
	if(TOP>=n){
		return;
	}
	stack[++TOP]=ch;
}
char POP(){
	if(TOP==-1){
		return;
	}
	--TOP;
	return stack[TOP+1];
}
void DISPLAY(){
	if(TOP==-1){
		return;
	}
	int tra=TOP;
	printf("stack==>");
	while(tra!=-1){
		printf("%c",stack[tra]);
		tra--;
	}
	printf("\n");
}
void main(){
	int i;
	char str[50];
	printf("Enter String Which Contains letters with star'*' :");
	gets(str);
	for(i=0;i<strlen(str);i++){
		if(str[i]!='*'){
			PUSH(str[i]);
		}
		else{
			POP();
		}
	}
	printf("Answer String : %s",stack);	
}
