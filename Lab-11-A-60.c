/*60. Write a program to implement stack using singly linked list. */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* first = NULL;
void PUSH(int info){//insert at begging
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = first;
	first = newNode; 
}
void POP(){
	if(first==NULL){
		return;
	}
	struct node *save = first;
	first = first->link;
	free(save);
}
void DISPLAY(){
	if(first==NULL){
		return;
	}
	struct node *save = first;
	while(save!=NULL){
		printf("%d->",save->info);
		save = save->link;
	}
	printf("\n");
} 
void main(){
	int i,n;
	printf("1.PUSH\n2.POP\n3.DISPLAY\n\n");
	printf("\t\t----------Enter -1 to Break a Loop.----------\n\n");
	while(1){
		printf("\nEnter a Choice:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		switch(n){
			case 1 : printf("Enter a Number:");
					 scanf("%d",&i);
					 PUSH(i);
					 break;
			case 2 : POP();
					 break;
			case 3 : DISPLAY();
					break;
		}
	}
}
