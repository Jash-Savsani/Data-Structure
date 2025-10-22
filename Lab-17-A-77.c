/*77. Write a program to check whether the given tree is symmetric or not. */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;
struct node* createNode(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->val = info;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
struct node* insert(int info,struct node* root){
	if(root == NULL){
		root = createNode(info);
		return root;
	}
	else if(info<root->val){
		root->left = insert(info,root->left);
	}
	else if(info>root->val){
		root->right = insert(info,root->right);
	}
	else{
		return root;	
	}
}
void preorder(struct node* root){
	if(root == NULL){
		return;
	}
	printf("%d,",root->val);
	preorder(root->left);
	preorder(root->right);
}
int isRootNull(struct node* root){
	if(root == NULL){
		return 0;
	}
	//return isSymmetricTree(root->left,root->right);
	return 1;
}
int isSymmetricTree(struct node* root1,struct node* root2){
	if(root1==NULL && root2==NULL){
		return 1;
	}
	else if(root1==NULL || root2==NULL){
		return 0;
	}
	else if(root1->val == root2->val){
		int val1 = isSymmetricTree(root1->left,root2->right);
		int val2 = isSymmetricTree(root1->right,root2->left);
		return (val1 && val2);
	}
	else{
		return 0;
	}
}
void main(){
	struct node* ptr1;
	struct node* ptr2;
	root = createNode(8);
	root->left = createNode(5);
	root->right = createNode(5);
	root->left->left = createNode(12);
	root->left->right = createNode(11);
	root->right->left = createNode(11);
	root->right->right = createNode(12);
	if(isRootNull(root) && isSymmetricTree(root->left,root->right)){
		printf("\nSymmetric Tree.");
	}
	else{
		printf("\nNon Symmetric Tree.");
	}
}

