/* WAP to check whether 2 singly linked lists are same or not.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* insert_At_Beggining(struct node* head,int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = head;
	head = newNode;
	return head;
}
void display_AllNodes(struct node* head){
	if(head==NULL){
		return;
	}
	struct node* save = head;
	while(save != NULL){
		printf("%d->", save->info);
		save = save->link;
	}
}
int count_Nodes(struct node* head){
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
int compare_LinkedList(struct node* head1,struct node* head2,int count1,int count2){
	if(head1==NULL || head2==NULL){
		printf("LinkedList is not Availabel.");
	}
	struct node* save1 = head1;
	struct node* save2 = head2;
	while(count1!=0 && count2!=0){
		if((save1->info == save2->info)&&(save1!=NULL && save2!=NULL)){
			save1 = save1->link;
			save2 = save2->link;
			count2--;
		}
		count1--;
	}
	if(count1==0 && count2==0){
		return 1;
	}
	else{
		printf("%d,%d",	save1->info,save2->info);
		return 0;
	}
}
void main(){
	int n,count1,count2;
	printf("\t\t-------Enter -1 to Break a Loop--------\n\n");
	while(1){
		printf("\nEnter Number to Insert in LinkedList:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		head1=insert_At_Beggining(head1,n);
	}
	while(1){
		printf("\nEnter Number to Insert in LinkedList:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		head2=insert_At_Beggining(head2,n);
	}
	printf("\nTwo Linked List Are:\n1.==>");
	display_AllNodes(head1);
	printf("\n2.==>");
	display_AllNodes(head2);
	count1=count_Nodes(head1);
	count2=count_Nodes(head2);
	n=compare_LinkedList(head1,head2,count1,count2);
	if(n==0){
		printf("\nLinkedLists Are Not Same.");
	}
	else{
		printf("\nLinkedLists Are Same.");
	}
}
