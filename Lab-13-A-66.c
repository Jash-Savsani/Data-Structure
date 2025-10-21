/*Sort LinkedList*/
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
void sort_LinkedList(){
	int i,j,count=0,temp;
	if(first==NULL || first->link==NULL){
		printf("Sorting is Not Available.");
		return;
	}
	struct node* curr = first;
	while(curr != NULL){
		count++;
		curr = curr->link;
	}
	for(i=1;i<count;i++){
		 curr = first;
		for(j=1;j<count;j++){
			if(curr->info > curr->link->info){
				temp = curr->link->info;
				curr->link->info = curr->info;
				curr->info = temp;
			}
			curr = curr->link;
		}
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
	sort_LinkedList();
	printf("\nAfter Sorting LinkedList:");
	display_AllNodes();
}
