#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* first= NULL;
void insert_Begging(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = first;
	first = newNode;
}
struct node* reverse_LinkedList(){
	if(first==NULL || first->link==NULL){
		return first;
	}
	struct node* save = first;
	struct node* pred = first;
	struct node* last = first;
	while(save->link != NULL){
		save = save->link;
	}
	last = save;
	while(first->link != NULL){
		save = first;
		pred = first;
			while(save->link != NULL){
				pred = save;
				save = save->link;	
			}
		save->link = pred;
		pred->link = NULL;
	}
	first = last;
	return first;
}
void display_AllNodes(){
	if(first==NULL){
		return;
	}
	struct node* save = first;
	while(save != NULL){
		printf("%d->", save->info);
		save = save->link;
	}
}
void main(){
	int i,n;
	printf("\t\t------Enter -1 to Break LinkedList-----\n\n");
	while(1){
		printf("Enter New Elemet in Linked List:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		insert_Begging(n);
	}
	printf("Simple LinkedList: ");
	display_AllNodes();
	first =  reverse_LinkedList();
	printf("\nReverse LinkedList: ");
	display_AllNodes();
}
