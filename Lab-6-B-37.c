/*37. Valid Parenthesis Problem 
Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
Now Chef wants to know if the given string is balanced or not.  
If is balanced then print 1, otherwise print 0.  
A balanced parenthesis string is defined as follows: 
� The empty string is balanced 
� If P is balanced then (P), {P}, [P] is also balanced 
� if P and Q are balanced PQ is also balanced 
� "([])", "({})[()]" are balanced parenthesis strings  
� "([{]})", "())" are not balanced.*/
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
	char check,str[50];
	printf("Enter String Which Contains Valid Brakets:");
	gets(str);
	for(i=0;i<strlen(str);i++){
		if(str[i]=='['||str[i]=='('||str[i]=='{'){
			PUSH(str[i]);
		}
		else if(str[i]==']'||str[i]==')'||str[i]=='}'){
			check=POP();
			if(check=='['&&str[i]==']'){
				continue;
			}
			else if(check=='('&&str[i]==')'){
				continue;
			}
			else if(check=='{'&&str[i]=='}'){
				continue;
			}
			else{
				break;	
			}
		}
		}
	
	if(i==strlen(str) && TOP==-1){
		printf("\nValid String.");
	}
	else{
		printf("\nInvalid String.");
	}
}
