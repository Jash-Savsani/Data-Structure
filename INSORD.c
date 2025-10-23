#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node* INSORD(struct node* FIRST,int info){
	struct node* NEW = (struct node*) malloc (sizeof(struct node));
	NEW->info = info;
	if(FIRST==NULL){
		NEW->link = FIRST;
		FIRST = NEW;
		return FIRST;
	}
	struct node* SAVE =	FIRST;
	if(NEW->info <= SAVE->info){
		NEW->link = FIRST;
		FIRST = NEW;
		return FIRST;
	}
	while((SAVE->link!=NULL) && (NEW->info >= (SAVE->link)->info)){
		SAVE = SAVE->link;
	}
	NEW->link = SAVE->link;
	SAVE->link = NEW;
	return FIRST;
}
void print_LinkedList(struct node *FIRST){
	struct node *temp = FIRST;
	while(temp!=NULL){
		printf("%d->",temp->info);
		temp = temp->link;
	}
	printf("NULL");
}
void main(){
	struct node* FIRST=NULL;
	int i,j,n;
	printf("How many Element You Want to Add in LinkedList:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter %d. Element:",i);
		scanf("%d",&j);
		FIRST = INSORD(FIRST,j);
	}
	printf("Before Adding : ");
	print_LinkedList(FIRST);
	printf("\nEnter New Number Add in Ordered LinkedList:");
	scanf("%d",&n);
	FIRST = INSORD(FIRST,n);
	printf("After Adding : ");
	print_LinkedList(FIRST);
}
