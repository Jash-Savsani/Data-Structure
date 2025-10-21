/*reverse LinkedList*/
#include<stdio.h>
struct node{
	int info;
	struct node* link;
};
struct node* first = NULL;
void insert_At_Beggining(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = first;
	first = newNode;
}
void display_AllNodes(struct node *first){
	if(first==NULL){
		return;
	}
	struct node* save = first;
	while(save != NULL){
		printf("%d->", save->info);
		save = save->link;
	}
}
void revrse_LinkedList(){
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
void main(){
	int i;
	printf("\t\t------Enter -1 to break Loop");
	while(1){
		printf("Enter a Number:");
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		insert_At_Beggining(i);
	}
	printf("Simple LinkedList:");
	display_AllNodes(first);
	revrse_LinkedList(first);
	display_AllNodes(first);
}
