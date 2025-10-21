/*Insert gcd between nodes*/
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
int gcd_Calculate(int a, int b){
	int i,max,min;
	if(a<b){
		max = b;
		min = a;
	}
	else{
		max = a;
		min = b;
	}
	for(i=min;i>=1;i--){
		if(min%i==0 && max%i==0){
			min = i;
			break;
		}
	}
	return min;
}
void insert_gcd_LinkedList(){
	if(first==NULL || first->link==NULL){
		printf("Linked List is not capable to Find GCD.");
		return;
	}
	struct node *curr = first;
	struct node *next = curr->link;
	while(next != NULL){
		struct node* newNode = (struct node*) malloc (sizeof(struct node));
		newNode->info = gcd_Calculate(curr->info,next->info);
		newNode->link = next;
		curr->link = newNode;
		curr = newNode->link;
		next = next->link;
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
	display_AllNodes(first);
	insert_gcd_LinkedList(first);
	printf("\nGCD Added LinkedList:");
	display_AllNodes(first);
}
