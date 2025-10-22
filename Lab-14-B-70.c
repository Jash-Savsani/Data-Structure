/*. WAP to split a circular linked list into two halves*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *first = NULL;
struct node *last = NULL;
struct node *first1 = NULL;
struct node *last1 = NULL;
struct node *first2 = NULL;
struct node *last2 = NULL;
void display_AllNodes(struct node *first){
	struct node* save = first;
	if(first == NULL){
		printf("Circular Linked List is Empty.\n");
		return;
	}
	do{
		printf("%d->",save->info);
		save = save->link;
	}while(save != first);
	printf("\n");
}
void insert_AtBegging(int info){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	if(first==NULL){
		newNode->link = newNode;
		first = newNode;
		last = newNode;
		return;
	}
	newNode->link = first;
	last->link = newNode;
	first = newNode;
}
void split_Circular_Linked_List(struct node *first){
	if(first==NULL || first == last){
		printf("Circular Linked List cannot be Split.");
		return;
	}
	struct node* save = first;
	int count=0;
	int count2=0;
	do{
		save = save->link;
		count++;
	}while(save!=first);
	first1 = first;
	while(count2!=count){
		count2++;
		if(count2 == count/2){
			last1 = save;
			first2 = save->link;
		}
		save = save->link;
		if(count2 == count-1){
			last2 = save;
			break;
		}
	}
	last2->link = first2;
	last1->link = first1;
}
void main(){
	int n;
	printf("\t\t-------Enter -1 to Break a Loop-------\n\n");
	while(1){
		printf("Enter Element:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		insert_AtBegging(n);
	}
	printf("Simple Circular Linked List:");
	display_AllNodes(first);
	split_Circular_Linked_List(first);
	printf("\nFirst Circular Linked List:");
	display_AllNodes(first1);
	printf("\nSecond Circular Linked List:");
	display_AllNodes(first2);
}
