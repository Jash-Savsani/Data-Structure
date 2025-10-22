/*
81. Write a program to implement phone book dictionary using Binary Search Tree 
which provides following operations: 
• Add new entry in phone book,  
• Remove entry from phone book,  
• Search phone number  
• List all entries in ascending order of name and 
• List all entries in descending order of name 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char phone_no[11];
	char name[50];
	struct node* lptr;
	struct node* rptr;
};
struct node* root = NULL;
struct node* createNode(char phone_no[],char name[]){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->lptr = NULL;	
	newNode->rptr = NULL;
	strcpy(newNode->phone_no,phone_no);
	strcpy(newNode->name,name);
	return newNode;
}
struct node* insertNodeInBST(struct node* root,char phone_no[],char name[]){
	if(root == NULL){
		root = createNode(phone_no,name);
		return root;	
	}
	else if(strcmp(root->name,name)<0){
		root->rptr = insertNodeInBST(root->rptr,phone_no,name);
	}
	else if(strcmp(root->name,name)>0){
		root->lptr = insertNodeInBST(root->lptr,phone_no,name);
	}
	
		return root;
}
struct node* deleteNode(struct node* root,char name[]){
	if(root == NULL){
		return NULL;
	}
	else if(strcmp(root->name,name)<0){
		root->rptr = deleteNode(root->rptr,name);
	}
	else if(strcmp(root->name,name)>0){
		root->lptr = deleteNode(root->lptr,name);
	}
	else{
		struct node* rptr = root->rptr;
		struct node* save = rptr;
		while(save->lptr){
			save = save->lptr;
		}
		save->lptr = root->lptr;
		free(root);
		return rptr;
	}
}
int searchNode(struct node* root, char phone_no[]){
	if(root == NULL){
		return 0;
	}
	if(strcmp(root->phone_no,phone_no)==0){
		return 1;
	}
	int res1 = searchNode(root->lptr,phone_no);
	int res2 = searchNode(root->rptr,phone_no);
	return (res1||res2);
}
void listAssendingOrder(struct node* root){
	if(root == NULL){
		return;
	}
	listAssendingOrder(root->lptr);
	printf("\nName:%s  Phone No:%s",root->name,root->phone_no);
	listAssendingOrder(root->rptr);
}
void listDessendingOrder(struct node* root){
	if(root == NULL){
		return;
	}
	listDessendingOrder(root->rptr);
	printf("\nName:%s  Phone No:%s",root->name,root->phone_no);
	listDessendingOrder(root->lptr);
}
int main(){
	int i,n;
	char phone_no[11],name[50];
	printf("1.Add new entry in phone book\n2.Remove entry from phone book\n3.Search phone number\n4.List all entries in ascending order of name and\n5.List all entries in descending order of name.");
	printf("\n\n\t\t---------Enter -1 to Break a Loop-------\n\n");
	while(1){
		printf("\nEnter Number:");
		scanf("%d",&i);
		if(i == -1){
			break;
		}
		switch(i){
			case 1: printf("Enter New Preson Name:");
					scanf("%s",name);
					printf("Enter New Preson Phone Number:");
					scanf("%s",phone_no);
					root = insertNodeInBST(root,phone_no,name);
					break;
			case 2:printf("Enter Person Name to Delete From PhoneDairy:");
					scanf("%s",name);
					root = deleteNode(root,name);
					break;
			case 3:printf("Enter Which PhoneNo You want to Search:");
					scanf("%s",phone_no);
					if(searchNode(root,phone_no)){
						printf("Given %s is Found in Phone Dairy.\n",phone_no);
					}
					else{
						printf("Given %s is not Found in Phone Dairy.\n",phone_no);
					}
					break;
			case 4:printf("\nAssending Order By Name : ");
					listAssendingOrder(root);
					break;
			case 5:printf("\nDessending Order By Name : ");
					listDessendingOrder(root);
					break;
		}
	}	
	return 0;
}

