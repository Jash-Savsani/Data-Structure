/*62. WAP to remove duplicate elements from a singly linked list.*/
#include<stdio.h>//baaki che
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* first = NULL;
void PUSH(int info){//insert at begging
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = first;
	first = newNode; 
}
void DISPLAY(){
	if(first==NULL){
		return;
	}
	struct node *save = first;
	while(save!=NULL){
		printf("%d->",save->info);
		save = save->link;
	}
	printf("\n");
} 
void REMOVE_DUPLICATE(){
	if(first==NULL || first->link==NULL){
		return;
	}
	if((first->link->link==NULL) && (first->info == first->link->info)){
		first->link=NULL;
		first=NULL;
		return;
	}
	struct node* save1 = first;
	struct node* save2 = save1->link;
	struct node* pred1 = save1;
	struct node* pred2 = save2;
	while(save1->link != NULL){
		while(save2!= NULL){
			if(save1->info == save2->info && save1->link==save2){
				save1 = save2->link;
				save2 = save1->link;
			}
			else if(save1->info == save2->info){
					
			}
//			if(save1->info == save2->info){
//				if(save1==first){
//					first = first->link;
//				}
//				else{
//					pred1->link = save1->link;
//					free(save1);
//					save1 = pred1->link;
//				}
//				pred2->link = save2->link;
//			}
			pred2 = save2;
			save2 = save2->link;
			printf("j");	
		}
		pred1 = save1;
		save1 = save1->link;
		save2 = save1->link;
	}
}
void main(){
	int n;
	printf("\t\t----------Enter -1 to Break a Loop.----------\n\n");
	while(1){
		printf("\nEnter a Number:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		PUSH(n);
	}
	printf("Before:");
	DISPLAY();
	printf("\nAfter:");
	REMOVE_DUPLICATE();
	DISPLAY();
}
