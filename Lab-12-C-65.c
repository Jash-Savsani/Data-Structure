/*WAP to swap Kth node from beginning with Kth node from end in a singly linked 
list. */
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *link;
	int info;
};
struct node* first = NULL;
int total_nodes=0;
void insert_At_Begging(int n){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = n;
	newNode->link = first;
	first = newNode;
}
void display_AllNodes(){
	if(first==NULL){
		printf("Linked List is Empty:");
		return;
	}
	struct node *save = first;
	while(save!=NULL){
		printf("%d->",save->info);
		save = save->link;
		total_nodes++;
	}
}
void swap_K_From_Start_And_End(){
	if(first==NULL || first->link==NULL){
		printf("Swap is impossible");
		return;
	}
	int k_s,k_e;
	printf("\nEnter K:");
	scanf("%d",&k_s);
	if(k_s>total_nodes){
		printf("Swap is Impossible.");
		return;
	}
	k_e=total_nodes-k_s+1;
	if(k_e == k_s){
		return;
	}
	struct node *save1 = first;
	struct node *save2 = first;
	struct node *pred1 = save1;
	struct node *pred2 = save2;
	while(k_e!=1 || k_s!=1){
		if(k_e!=1){
			pred2 = save2;
			save2 = save2->link;
			k_e--;
		}
		if(k_s!=1){
			pred1 = save1;
			save1 = save1->link;
			k_s--;
		}
	}
	if(save1->link == save2 || save2->link == save1){//if two nodes available
		if(save1==first){
			save2->link = save1;
			save1->link = NULL;
			first = save2;
		}
		else{
			save1->link = save2;
			save2->link = NULL;
			first = save1;
		}
	}
	if(save1==first || save2==first){
		if(save1==first){
			save2->link = save1->link;
			pred2->link = save1;
			save1->link = NULL;
			first = save2;
		}
		else{//if k_e==1
			save1->link = save2->link;
			pred1->link = save2;
			save2->link = NULL;
			first = save1;
		}
		return;
	}
	if(k_s<k_e){
		struct node* temp = save2->link;
		pred1->link = save2;
		save2->link = save1->link;
		save1->link = temp;
		pred2->link = save1;	
	}
	else{
		struct node* temp = save1->link;
		pred2->link = save1;
		save1->link = save2->link;
		save2->link = temp;
		pred1->link = save2;
	}
	return;
}
int main(){
	int n;
	printf("\t\t---------- Enter -1 to Break a Loop------------\n\n");
	while(1){
		printf("Enter Number:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		insert_At_Begging(n);
	}
	printf("Before Swaping:");
	display_AllNodes();
	swap_K_From_Start_And_End();
	printf("\nAfter Swaping:");
	display_AllNodes();
	return 0;
}

