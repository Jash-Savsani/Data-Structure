#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
void print_LinkedList(struct node *FIRST){
	struct node *temp = FIRST;
	while(temp!=NULL){
		printf("%d->",temp->info);
		temp = temp->link;
	}
	printf("NULL");
}
void print_Addof_LinkedList(struct node *FIRST){
	struct node *temp = FIRST;
	while(temp!=NULL){
		printf("%d->",temp);
		temp = temp->link;
	}
	printf("NULL");
}
void DELETE(struct node* FIRST, int n){
	struct node* X = (struct node*) malloc (sizeof(struct node));
	X->link =n;
	if(FIRST==NULL){
		return;
	}
	struct node* PRED = FIRST;
	struct node* SAVE = FIRST;
	while((SAVE!=X->link) && (SAVE->link!=NULL)){
		PRED = SAVE;
		SAVE = SAVE->link;
	}
	if(SAVE!=X->link){
		printf("Node Not Found.");
	}
	if(X->link==FIRST){
		FIRST = FIRST->link;
		printf("savsani");
	}
	else{
		PRED->link = SAVE->link;
		free(SAVE);
	}	
} 
struct node* insert_at_Begging(struct node *FIRST,int info){
	struct node *New = (struct node*)  malloc (sizeof(struct node));
	New->info=info;
	New->link = FIRST;	
	FIRST = New;
	return FIRST;
}
void main(){
	struct node* FIRST=NULL;
	int i,j,n;
	printf("How many Element You Want to Add in LinkedList:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter %d. Element:",i);
		scanf("%d",&j);
		FIRST = insert_at_Begging(FIRST,j);
	}
	printf("Before Deleting : ");
	print_LinkedList(FIRST);
	printf("\nBefore Deleting(Address) : ");
	print_Addof_LinkedList(FIRST);
	printf("\nEnter Address For Delete in Ordered LinkedList:");
	scanf("%d",&n);
	DELETE(FIRST,n);
	printf("After Deleting : ");
	print_LinkedList(FIRST);
}
