/*Write a program to count the number of nodes in a singly circular linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* head = NULL;
void insert_At_Beggining(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = head;
	head = newNode;
}
void display_AllNodes(){
	if(head==NULL){
		return;
	}
	struct node* save = head;
	while(save != NULL){
		printf("%d->", save->info);
		save = save->link;
	}
}
int count_Nodes(){
	int count=0;
	if(head==NULL){
		return count;
	}
	count++;
	struct node* save = head;
	while(save->link != NULL){
		save = save->link;
		count++;
	}
	return count;
}
int main(){
	int i,n;
	printf("\t\t-------Enter -1 to Break a Loop--------\n\n");
	while(1){
		printf("\nEnter Number to Insert in LinkedList:");
		scanf("%d",&n);
		if(n==-1){
			i=count_Nodes();
			printf("\nTotal Nodes:%d",i);
			break;
		}
		insert_At_Beggining(n);
		display_AllNodes();
		i=count_Nodes();
		printf("\nTotal Nodes:%d",i);
	}
	return 0;
}
