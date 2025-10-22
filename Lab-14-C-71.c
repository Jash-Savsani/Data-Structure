/*
71. Write a program to perform addition of two polynomial equations using 
appropriate data structure. 
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *lptr;
	struct node *rptr;
	int power;
};
struct node *first1 = NULL;
struct node *first2 = NULL;
struct node *first3 = NULL;
struct node *save1 = NULL;
struct node *save2 = NULL;
struct node *save3 = NULL;
struct node* insert_AtBegging(struct node* first,int info,int power){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->power = power;
	newNode->lptr = NULL;
	if(first==NULL){
		newNode->rptr = NULL;
		first = newNode;
		return first; 
	}
	newNode->rptr = first;
	first->lptr = newNode;
	first = newNode;
	return first;
}
void display_AllNodes(struct node *first){
	if(first==NULL){
		printf("Doubly LinkedList is Empty.\n");
		return;
	}
	struct node *save = first;
	while(save != NULL){
		printf("%d,%d->",save->info,save->power);
		save = save->rptr;
	}
	printf("\n");
	return;
}
struct node* sum_of_Polynomial(struct node *first1,struct node *first2){
	if(first1==NULL && first2==NULL){
		printf("Both Polynomial is Empty.");
		return NULL;
	}
	if(first1==NULL){
		return first2;
	}
	if(first2==NULL){
		return first1;
	}
	int i=0;
	save1 = first1;
	save2 = first2;
	save3 = first3;
	while(save1!=NULL){
		struct node *newNode = (struct node*) malloc (sizeof(struct node));
		save2 = first2;
		while(save2!=NULL){
			if(save1->power == save2->power){
				newNode->power = save1->power;
				newNode->info = save1->info + save2->info;
				if(save2->lptr == NULL && save2->rptr ==NULL){
					free(save2);
				}
				else if(save2 == first2){
					first2 = first2->rptr;
					first2->lptr = NULL;
				}
				else if(save2->rptr == NULL){
					save2 = save2->lptr;
					save2->rptr = NULL;
				}
				else{
					save2->lptr->rptr = save2->rptr;
					save2->rptr->lptr = save2->lptr;
					free(save2);
				}
				i++;
				break;
			}
			save2 = save2->rptr;
		}
		newNode->rptr = first3;
		newNode->lptr = NULL;
		first3 = newNode;
		if(i==1){
			i--;	
		}
		else{
			newNode->info = save1->info;
			newNode->power = save1->power;
		}
		save1 = save1->rptr;
	}
	return first3;	
}
void main(){
int n,power;
	printf("\t\t---------Enter -1 to Break a Loop-----------\n\n");
	while(1){
		printf("Enter a Number:");
		scanf("%d",&n);
		fflush(stdin);
		if(n==-1){
			break;
		}
		printf("Enter It's Power:");
		scanf("%d",&power);
		first1=insert_AtBegging(first1,n,power);
	}	
	printf("\n First Doubly Linked List:");
	display_AllNodes(first1);
	printf("\n\n\t\t---------Enter -1 to Break a Loop-----------\n\n");
	while(1){
		printf("Enter a Number:");
		scanf("%d",&n);
		fflush(stdin);
		if(n==-1){
			break;
		}
		printf("Enter It's Power:");
		scanf("%d",&power);
		first2=insert_AtBegging(first2,n,power);
	}	
	printf("\nSecond Doubly Linked List:");
	display_AllNodes(first2);
	first3=sum_of_Polynomial(first1,first2);
	printf("\nSum Doubly Linked List:");
	display_AllNodes(first3);
}

