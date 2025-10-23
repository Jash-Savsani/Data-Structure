#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
void print_LinkedList(struct node *FIRST){
	struct node *temp = FIRST;
	while(temp!=NULL){
		printf("%d->",temp->info);
		temp = temp->link;
	}
	printf("NULL");
}
struct node* insert_at_Begging(struct node *FIRST,int info){
	struct node *New = (struct node*)  malloc (sizeof(struct node));
	New->info=info;
	New->link = FIRST;	
	FIRST = New;
	return FIRST;
}
struct node* copy_LinkedList(struct node* FIRST){
	if(FIRST==NULL){
		return FIRST;
	}
	struct node *New = (struct node*) malloc (sizeof(struct node));
	New->info = FIRST->info;
	New->link = NULL;
	struct node *BEGIN = New;
	struct node *SAVE = FIRST->link;
	struct node *PRED = New;
	while(SAVE != NULL){
		struct node *New1 = (struct node*)  malloc (sizeof(struct node));
		New1->info = SAVE->info;
		New1->link = NULL;
		PRED->link = New1;
		PRED = New1;
		SAVE = SAVE->link;
	}
	return BEGIN;
}
void main(){
	struct node* FIRST=NULL;
	struct node* BEGIN=NULL;
	int i=1,j,n;
	printf("\n----If You Want to Brake A Loop Enter -1----\n\n");
	while(1){
		printf("Enter %d. Element:",i++);
		scanf("%d",&j);
		if(j==-1){
			break;
		}
		FIRST = insert_at_Begging(FIRST,j);	
	}
	printf("\nOriginal LinkedList:");
	print_LinkedList(FIRST);
	printf("\nCopy LinkedList:");
	BEGIN = copy_LinkedList(FIRST);
	print_LinkedList(BEGIN);
}
