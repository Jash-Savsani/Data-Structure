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
void main()
{
	int i,n,j,total=0;
	printf("How many Element You Want to Add in LinkedList:");
	scanf("%d",&n);
	struct node *head = NULL;
	for(i=1;i<=n;i++){
		printf("Enter %d. Element:",i);
		scanf("%d",&j);
		head = insert_At_Begging(head,j);
	}
	struct node *ptr = head;
	while(ptr != NULL){
		total += ptr->info;
		ptr = ptr->link;
	}
	struct node *Total = (struct node*) malloc (sizeof(struct node));
	Total->info=total;
	Total->link=head;
	head=Total;
	ptr=head;
	printf("\nHere We insert Total as First Node in LinkedList.\n");
	while(ptr != NULL){
		printf("%d->",ptr->info);
		ptr = ptr->link;
	}
	printf("NULL");
}
