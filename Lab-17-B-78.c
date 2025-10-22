/*
78. Given a binary tree, determine if it is height-balanced (A height-balanced binary 
tree is a binary tree in which the depth of the two subtrees of every node never 
differs by more than one).
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int val;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;
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
int max(int a,int b){
	return (a>=b) ? a : b;
}
int heightFind(struct node* root){
	if(root == NULL){
		return 0;
	}
	int l = heightFind(root->left);
	int r= heightFind(root->right);
	int m = max(l,r);
	return m+1;
}
int isBalancedTree(struct node* root){
	if(root == NULL){
		return 1;//Because NULL Tree is Also Balanced Tree.
	}
	int le = heightFind(root->left);
	int ri= heightFind(root->right);
	int diff = 0;
	if(le > ri){
		diff = le-ri;
	}
	else{
		diff = ri-le;
	}
	if(diff > 1){
		return 0;
	}
	else{
		return(isBalancedTree(root->left) && isBalancedTree(root->right));
	}
}
void main(){
	root = createNode(3);
	root->left = createNode(9);
	root->right = createNode(20);
	root->right->left = createNode(15);
	root->right->right = createNode(7);
	if(isBalancedTree(root)){
		printf("\nGiven Tree is Height Balanced.");
	}
	else{
		printf("\nGiven Tree is not Height Balanced.");
	}
}
