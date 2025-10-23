#include<stdio.h>//if you dont want to use double pointer you have to make function with return type struct Node*
struct Node{
	int info;
	struct Node *link;
};
void addNode(struct Node **first, int data){//insert at ending
	struct Node *newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->info = data;
	newNode->link = NULL;
	if(*first == NULL){
		*first = newNode;
	}
	else{
		struct Node *temp = *first;
		while(temp->link != NULL){
			temp = temp->link;
		}
		temp->link = newNode;
	}
}
void printList(struct Node *first){
	struct Node *temp = first;
	while(temp != NULL){
		printf("%d->",temp->info);
		temp = temp->link;
	}
	
}
void main(){
	int i;
	struct Node *first = NULL;
	for(i=1;i<=5;i++){
	addNode(&first,10);//cause for modify	
	}
	printList(first);//cause for not modify
	
}
