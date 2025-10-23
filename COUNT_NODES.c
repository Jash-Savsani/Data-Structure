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
struct node* insert_at_Begging(struct node *FIRST,int info){
	struct node *New = (struct node*)  malloc (sizeof(struct node));
	New->info=info;
	New->link = FIRST;	
	FIRST = New;
	return FIRST;
}
int count_Nodes(struct node *FIRST){
	int count=0;
	if(FIRST==NULL){
		count=0;
		return count;	
	}
	struct node *SAVE = FIRST;
	while(SAVE != NULL){
		SAVE = SAVE->link;
		count++;
	}
	return count;
}
void main(){
	struct node* FIRST=NULL;
	int i=1,j,n;
	printf("\n----If You Want to Brake A Loop Enter -1----\n\n");
	while(1){
		printf("Enter %d. Element:",i++);
		scanf("%d",&j);
		if(j==-1){
			break;
		}
		FIRST = insert_at_Begging(FIRST,j);	
	}
	n=count_Nodes(FIRST);
	printf("Total Nodes:%d",n);
}
