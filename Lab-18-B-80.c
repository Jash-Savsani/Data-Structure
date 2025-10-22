/*80. WAP to find the smallest and largest elements in the Binary Search Tree. */
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
int smallest(struct node* root){
	if(root == NULL){
		printf("BST is Empty.");
		return -1;
	}
	if(root->left == NULL){
		return root->val;
	}
	return smallest(root->left);
}
int largest(struct node* root){
	if(root == NULL){
		printf("BST is Empty.");
		return -1;
	}
	if(root->right == NULL){
		return root->val;
	}
	return largest(root->right);
}
void main(){
	root = createNode(30);
	root->left = createNode(20);
	root->right = createNode(40);
	root->right->left = createNode(35);
	root->right->right = createNode(50);
	root->left->left = createNode(10);
	root->left->right = createNode(25);
	int s = smallest(root);
	int l = largest(root);
	printf("Smallest Element in BST is : %d\nLargest Element in BST is : %d",s,l);
}
