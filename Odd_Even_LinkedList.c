#include<stdio.h>
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
struct node* odd_even_LinkedList(struct node *head,int size){//baaki che.
	if(size<=1){
		return head;
	}
	else{
		struct node *ptr1 = head;
		struct node *ptr2 = head;
		while(size>=1){
			while(ptr2->link != NULL){
				ptr2 = ptr2->link;			
			}
			while(ptr1->link != ptr2){
				ptr1 = ptr1->link;
			}
			if(ptr2->info % 2 != 0){
				ptr2->link = head;
				head = ptr2;
				ptr1->link = NULL;
		 	}
			ptr1 = head;
			size--;
		}
		return head;
	}
}
void print_LinkedList(struct node *head){
	struct node *temp = head;
	while(temp!=NULL){
		printf("%d->",temp->info);
		temp = temp->link;
	}
	printf("NULL");
}
void main()
{
	int i,j,n;
	printf("How many Element You Want to Add in LinkedList:");
	scanf("%d",&n);
	struct node *head = NULL;
	for(i=1;i<=n;i++){
		printf("Enter %d. Element:",i);
		scanf("%d",&j);
		head = insert_At_Begging(head,j);
	}
	printf("Before Sorting : ");
	print_LinkedList(head);
	head = odd_even_LinkedList(head,n);
	printf("\nAfter Sorting : ");
	print_LinkedList(head);
}
