/*76. Write a program to check whether the given two trees are same or not.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* left;
	struct node* right;
};
struct node* root1 = NULL;
struct node* root2 = NULL;
struct node* createNode(int data){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;		
}
struct node* insert(int data,struct node* root){
	if(root == NULL){
		root = createNode(data);
		return root;
	}
	else if(root->val > data){
		root->left = insert(data,root->left);
	}
	else if(root->val < data){
		root->right = insert(data,root->right);
	}
	else{
		return root;//when node with same value again come in insertion
	}
}
int sameTree(struct node* root1,struct node* root2){
	if(root1==NULL && root2==NULL){
		return 1;
	}
	else if(root1==NULL || root2==NULL){//If any one Root Existance and Other Root does'nt Existance.
		return 0;
	}
	else if(root1->val == root2->val){
		int val1 = sameTree(root1->left,root2->left);
		int val2 = sameTree(root1->right,root2->right);
		return (val1 && val2);
	}
	else{
		return 0;
	}
}
void main(){
	int i,n;
	printf("\t\t------Enter -1 to break Loop----------\n");
	while(1){
		printf("\nEnter a Vlaue in BST root1:");
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		root1 = insert(i,root1);
	}
	while(1){
		printf("\nEnter a Vlaue in BST root2:");
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		root2 = insert(i,root2);
	}
	i = sameTree(root1,root2);
	if(i==0)
		printf("\nBoth Tree Are Not Same.");
	else
		printf("\nBoth Tree Are Same.");
}
