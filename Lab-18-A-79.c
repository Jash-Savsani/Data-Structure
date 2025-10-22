/*79. Write a program to construct a binary tree from given Postorder and Preorder 
traversal sequence.*/
#include<stdio.h>/*Bakki che.*/
#include<stdlib.h>
struct node{
	int val;
	struct node* lptr;
	struct node* rptr;
};
struct node* root = NULL;
struct node* createNode(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->lptr = NULL;
	newNode->rptr = NULL;
	newNode->val = info;
}
void preOrder(struct node* root){
	if(root == NULL){
		return;
	}
	printf("%d, ",root->val);
	preOrder(root->lptr);
	preOrder(root->rptr);
}
struct node* createBST(int preorder[],int postorder[],int* preindex,int firstPre,int lastPre,int size){
	if(root == NULL || firstPre>lastPre){
		return;
	} 
	root = createNode(preorder[*preindex]);
	(preindex)++;
	if(firstPre>=lastPre)
}
void main(){
}
