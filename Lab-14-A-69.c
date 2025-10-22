/* Write a menu driven program to implement following operations on the circular 
linked list. 
• Insert a node at the front of the linked list. 
• Delete a node from specified position. 
• Insert a node at the end of the linked list. 
• Display all nodes.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *first = NULL;
struct node *last = NULL;
void insert_AtBegging(int info){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	if(first==NULL){
		newNode->link = newNode;
		first = newNode;
		last = newNode;
		return;
	}
	newNode->link = first;
	last->link = newNode;
	first = newNode;
}
void insert_AtEnding(int info){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	if(first==NULL){
		newNode->link = newNode;
		first = newNode;
		last = newNode;
		return;
	}
	newNode->link = first;
	last->link = newNode;
	last = newNode;
}
void delete_Node_Specified_Position(int position){
	if(first==NULL){
		printf("Circuler Linked List is Empty.\n");
		return;
	}
	struct node* save = first;
	struct node* pred = first;
	while(position!=1){
		pred = save;
		save = save->link;
		position--;
	}
	pred->link = save->link;
	free(save);
}
void display_AllNodes(){
	struct node* save = first;
	if(first == NULL){
		printf("Circular Linked List is Empty.\n");
		return;
	}
	do{
		printf("%d->",save->info);
		save = save->link;
	}while(save != first);
	printf("\n");
}	
void main(){
	int i,n;
	printf("1)Insert a node at the front of the linked list.\n2)Delete a node from specified position. \n3)Insert a node at the end of the linked list. \n4) Display all nodes.\n");
	printf("\t\t--------Enter -1 to Break Loop---------\n\n");
	while(1){
		printf("Eneter Choise No:");
		scanf("%d",&i);
		switch(i){
			case 1 : printf("Enter Number:");
					 scanf("%d",&n);
					 insert_AtBegging(n);
					 break;
			case 2 : display_AllNodes();
					 printf("\nEnter Specifed Position:");
					 scanf("%d",&n);
					 delete_Node_Specified_Position(n);
					 break;
			case 3 : printf("Enter Number:");
					 scanf("%d",&n);
					 insert_AtEnding(n);
					 break;
			case 4 : display_AllNodes();
					 break;
			default : return;
		}
		if(i==-1){
			break;
		}
	}	
}
