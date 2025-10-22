/*WAP to delete alternate nodes of a doubly linked list. */
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
void alternate_DoublyLinkedList(){
	if(l==NULL || l->rptr==NULL){
		printf("Alteration Can't be Possible.\n");
		return;
	}
	struct node *ptr = l;
	struct node *curr = l->rptr;
	while((curr != r) && (ptr != r)){
		ptr->rptr = curr->rptr;
		curr->rptr->lptr = ptr;
		free(curr);
		ptr = ptr->rptr;
		curr = ptr->rptr;
	}
	if(curr == r){
		r = r->lptr;
		r->rptr = NULL;
		free(curr);
	}
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
	int n;
	printf("\t\t---------Enter -1 to Break a Loop-----------\n\n");
	while(1){
		printf("Enter a Number:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		insert_AtBegging(n);
	}	
	printf("\nSimple Doubly Linked List:");
	display_AllNodes();
	alternate_DoublyLinkedList();
	printf("\nAlternate Doubly Linked List:");
	display_AllNodes();
}
