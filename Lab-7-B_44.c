/*44. Write a program for evaluation of prefix Expression using Stack. */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>//for isdigit() function use.
char postfix[100];
int stack[100];
int operand1,operand2,top=-1,value;
void push(int n){
	if(top>=100){
		printf("Stack Overflow.");
		return;
	}
	stack[++top] = n;
}
int pop(){
	if(top==-1){
		printf("Stack Underflow.");
		return -1;
	}
	return stack[top--];
}
int PERFORM_OPERATION(char op,int operand2,int operand1){
	switch(op){
		case '+':return operand1 + operand2;
		case '-':return operand1 - operand2;
		case '*':return operand1 * operand2;
		case '/':return operand1 / operand2;
		case '^':return pow(operand1,operand2);
	}
}
void EVALUATE_POSTFIX(){
	int i;
	for(i=strlen(postfix)-1;i>=0;i--){
		if(postfix[i]>='0' && postfix[i]<='9'){
			value = postfix[i]-'0';
			push(value);
		}
		else{
			operand1=pop();
			operand2=pop();
			value = PERFORM_OPERATION(postfix[i],operand2,operand1);
			push(value);
		}
	}
	value = pop(); 
	printf("\n\nAnswer is : %d",value);
}
void main(){
	printf("Enter Prefix for Evalute:");
	scanf("%s",postfix);
	EVALUATE_POSTFIX();
}
