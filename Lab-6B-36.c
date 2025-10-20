//B 36. Write a program to determine if an input character string is of the form aibi 
//where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’. 
#include<stdio.h>
#include<string.h>
int TOP=-1;//topmost of array
char stack[]="";
void PUSH(char ch){
	if(TOP>strlen(stack)-1){
		printf("A_Stack Over Flow.");
		return;
	}
	TOP+=1;
	stack[TOP] = ch;
	return;
}
char POP(){
	if(TOP==-1){
		printf("B_Stack UnderFlow.\n");
		return '\0';
	}
	TOP-=1;
	return stack[TOP+1];
} 
void DISPLAY(){
	if(TOP==-1){
		printf("C_Stack UnderFlow.\n");
		return;
	}
	int i;
	for(i=TOP;i>=0;i--){
		printf("%c->",stack[i]);
	}printf("\n");
}
void ab_Type_String(char str[]){
	int i=0;
	while(str[i]!='b'){
		PUSH(str[i]);
		i++;
	}
	while(str[i]!='\0' && TOP!=-1){
		i++;
		char ch = POP();
	}
	if(str[i]=='\0' && TOP==-1){
		printf("\nGiven String is Valid.");
	}else{
		printf("\nGiven String is Invalid.");
	} 
}
void main(){
	char str[50];
	printf("Enter String(aabb type):");
	scanf("%s",str);
	ab_Type_String(str);
}
