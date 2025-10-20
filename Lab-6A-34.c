/*Write a menu driven program to implement following operations on the Stack 
using an Array 
• PUSH, POP, DISPLAY 
• PEEP, CHANGE*/
#include<stdio.h>/*Bakki che*/
int TOP=-1;//topmost of array
int n;//size of array
void PUSH(int stack[],int X){
	if(TOP>=n-1){
		printf("Stack Over Flow.");
		return;
	}
	TOP+=1;
	stack[TOP] = X;
	return;
}
int POP(int stack[]){
	if(TOP==-1){
		printf("Stack UnderFlow.\n");
		return -1;
	}
	TOP-=1;
	return stack[TOP+1];
} 
void DISPLAY(int stack[]){
	if(TOP==-1){
		printf("Stack UnderFlow.\n");
		return;
	}
	int i;
	for(i=TOP;i>=0;i--){
		printf("%d->",stack[i]);
	}printf("\n");
}
int PEEP(int stack[],int I){
	if(TOP-I+1<=-1){
		printf("Stack Underflow.\n");
		return -1;
	}
	return stack[TOP-I+1];
}
void CHANGE(int stack[],int I,int J){
	if(TOP-I+1<=-1){
		printf("Stack Underflow.\n");
		return;
	}
    stack[TOP-I+1] = J;
}
void main()
{
	int i,j,choise;
	printf("1.PUSH\n2.POP\n3.DISPLAY\n4.PEEP\n5.CHANGE\n\n");
	printf("Enter size of Stack:");
	scanf("%d",&n);
	int stack[n];
	printf("Stack Size:%d\n",n);
	printf("\n\n\t\t----------Enter -1 to Break a Loop.----------\n\n");
	while(1){
		printf("\nEnter a Choise:");
		scanf("%d",&choise);
		switch(choise){
			case 1 : printf("Enter a Number:");
					 scanf("%d",&i);
					 PUSH(stack,i);
					 break;
			case 2 : j = POP(stack);
					 printf("POP:%d\n",j);
					 break;
			case 3: DISPLAY(stack);
			         break;
			case 4 : printf("Enter Ith idex from top:");
					 scanf("%d",&i);
					 j = PEEP(stack,i);
					 printf("PEEP:%d\n",j);
					 break;
			case 5 : printf("Enter Ith idex from top:");
					 scanf("%d",&i);
					 printf("Enetr a New Value:");
					 fflush(stdin); 
					 scanf("%d",&j);
					 CHANGE(stack,i,j);
					 break;  
		}	
	}	
}
