/*61. Write a program to implement queue using singly linked list. */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* first = NULL;
void insert_At_Begging(int info){//insert at begging
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = first;
	first = newNode;
}
void delete_from_last(){
	if(first == NULL){
		return;
	}
	struct node *save = first;
	struct node *pred = first;
	while(save->link != NULL){
		pred = save;
		save = save->link;
	}
	pred->link = NULL;
	free(save);
}//delete from last
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
	printf("1.INSERT\n2.DELETE\n3.DISPLAY\n\n");
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
					 insert_At_Begging(i);
					 break;
			case 2 : delete_from_last();
					 break;
			case 3 : DISPLAY();
					break;
		}
	}
}
