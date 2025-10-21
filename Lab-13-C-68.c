/*Swap nodes*/
#include<stdio.h>
#include<stdlib.h>
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
void swap_LinkedList(){
	int i=0;
	if(first==NULL || first->link==NULL){
		printf("Sorting is Not Available.");
		return;
	}
	struct node* curr = first;
	struct node* next = first->link;
	struct node* temp = next->link;
	first = next;
	next->link = curr;
	curr->link = temp;
	if(temp->link == NULL){//only two nodes avalilable
		return;
	}
	else{//three or more than
		struct node* ptr1 = first;
		while(temp != NULL){
			for(i=1;i<=2;i++){
				temp = temp->link;
				next = next->link;	
				curr = curr->link;
			}
			ptr1 = ptr1->link;
			curr->link = next;
			next->link = temp;
			ptr1->link = curr;
			next = ptr1->link;
			curr = curr->link;
			ptr1 = ptr1->link;
		}
		return;
	} 
}
void main(){
	int i;
	printf("\t\t------Enter -1 to break Loop-------\n");
	while(1){
		printf("Enter a Number:");
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		insert_At_Beggining(i);
	}
	printf("Simple LinkedList:");
	display_AllNodes();
	swap_LinkedList();
	printf("\nAfter Swaping LinkedList:");
	display_AllNodes();
}
