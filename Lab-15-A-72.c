/*
72. Write a menu driven program to implement following operations on the doubly 
linked list. 
• Insert a node at the front of the linked list. 
• Delete a node from specified position. 
• Insert a node at the end of the linked list. (Home Work) 
• Display all nodes. (Home Work) 
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *lptr;
	struct node *rptr;
};
struct node *l = NULL;
struct node *r = NULL;
void insert_AtBegging(int info){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->lptr = NULL;
	if(l==NULL){
		newNode->rptr = NULL;
		l = newNode;
		r = newNode;
		return; 
	}
	newNode->rptr = l;
	l->lptr = newNode;
	l = newNode;
	return;
}
void delete_SpecifiedPosition(int position){
	if(l==NULL){
		printf("Doubly Linked List is Empty.\n");
		return;
	}
	struct node *save = l;
	while(position != 1){
		position--;
		save = save->rptr;
	}
	if(l==r){
		free(l);
		return;
	}
	if(save == l){
		l = l->rptr;
	}
	else if(save == r){
		r = r->lptr;
	}
	else{
		save->lptr->rptr = save->rptr;
		save->rptr->lptr = save->lptr;
	}
	free(save);
	return;
}
void insert_AtEnding(int info){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->rptr = NULL;
	if(r==NULL){
		newNode->lptr = NULL;
		l = newNode;
		r = newNode;
		return; 
	}
	newNode->lptr = r;
	r->rptr = newNode;
	r = newNode;
	return;
}
void display_AllNodes(){
	if(l==NULL){
		printf("Doubly LinkedList is Empty.\n");
		return;
	}
	struct node *save = l;
	while(save != NULL){
		printf("%d->",save->info);
		save = save->rptr;
	}
	printf("\n");
}
void main(){
	int i,n;
	printf("\t\t--------Enter -1 to Break a Loop--------\n");
	printf("\n1.Insert a node at the front of the linked list.\n2.Delete a node from specified position.\n3.Insert a node at the end of the linked list. (Home Work)\n4.Display all nodes.\n\n");
	while(1){
		printf("Enter a Number:");
		scanf("%d",&n);
		switch(n){
			case 1 : printf("\nEnter a Number:");
					 scanf("%d",&i);
					 insert_AtBegging(i);
					 break;
			case 2 : display_AllNodes();
					 printf("\nEnter Position:");
					 scanf("%d",&i);
					 delete_SpecifiedPosition(i);
					 break;
			case 3 : printf("\nEnter a Number:");
					 scanf("%d",&i);
					 insert_AtEnding(i);
					 break;
			case 4 : printf("Your Doubly Linked List:");
					display_AllNodes();
		            break;
		}
	}
}
