#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node* insert_At_Begging(struct node *head,int info){
	struct node *New = (struct node*) malloc (sizeof(struct node));
	New->info = info;
	New->link = head;
	head = New;
	return head;
}
void print_LinkedList(struct node *head){
	struct node *temp = head;
	while(temp!=NULL){
		printf("%d->",temp->info);
		temp = temp->link;
	}
	printf("NULL");
}
struct node* remove_Nth_End_Ofthe_LinkedList(struct node *head,int temp){
	struct node* ptr1 = head;
	struct node* ptr2 = head;
	struct node* ptr3 = head;
	int n,i=1;
	printf("\nEnter Nth Node From End of The List To Remove:");
	scanf("%d",&n);
	while(i != (temp-n)){
		ptr1 = ptr1->link;
		i++;
	}
	i=1;
	while(i != (temp-n+2)){
		ptr2 = ptr2->link;
		i++;
	}
	ptr3 = ptr1->link;
	ptr1->link = ptr2;
	ptr3->link = NULL;
	return head;
}
void main()
{
	struct node *head = NULL;
	int n,i,j;
	printf("How many Elements You Want to Add in LinkedList:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter %d. Element:",i);
		scanf("%d",&j);
		head = insert_At_Begging(head,j);
	}
	print_LinkedList(head);
	head = remove_Nth_End_Ofthe_LinkedList(head,n);
	printf("After Removing Nth Last of LinkedList:");
	print_LinkedList(head);	
}
