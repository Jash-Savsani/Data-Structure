/*Copy Linked List*/
#include<stdio.h>
struct node{
	int info;
	struct node* link;
};
struct node* first = NULL;
struct node* copy = NULL;
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
void copy_List(struct node *first){
	if(first==NULL){
		printf("Given Linked List Empty.");
		return;
	}
	struct node *save = first;
	copy = (struct node*) malloc (sizeof(struct node));
	struct node *pred = copy;
	pred->info = save->info;
	while(save->link != NULL){
		struct node *newNode = (struct node*) malloc (sizeof(struct node)); 
		newNode->info = save->link->info;
		pred->link = newNode;
		save = save->link;
		pred = pred->link;
	}
	pred->link = NULL;
}
void main(){
	int i;
	printf("\t\t-----Enter -1 to Break Loop\n");
	while(1){
		printf("Enter Number:");
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		insert_At_Beggining(i);
	}
	printf("Simple LinkedList:");
	display_AllNodes(first);
	copy_List(first);
	printf("\nCopy LinkedList:");
	display_AllNodes(copy);
}
