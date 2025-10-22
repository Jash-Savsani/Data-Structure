/*
75. Write a menu driven program to implement Binary Search Tree (BST) & perform 
following operations:  
• Insert a node 
• Delete a node 
• Search a node 
• Preorder Traversal 
• Postorder Traversal 
• Inorder Traversal
*/
#include<stdio.h>
#include<stdlib.h>
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
void preorder(struct node* root){
	if(root == NULL){
		return;
	}
	printf("%d, ",root->val);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d, ",root->val);
	inorder(root->right);
}
void postorder(struct node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d, ",root->val);
}
int search(int data,struct node* root){
	if(root == NULL){
		return 0;
	}
	if(root->val == data){
		return 1;
	}
	int res1 = search(data,root->left);
	int res2 = search(data,root->right);
	return (res1 || res2);	
}
struct node* deleteNode(int data,struct node* root){
	if(root == NULL){
		return;
	}
	else if(root->val > data){
		root->left = deleteNode(data,root->left);
	}
	else if(root->val < data){
		root->right = deleteNode(data,root->right);
	}
	else{
		struct node* right = root->right;
		struct node* save = right;
		while(save->left){
			save = save->left;
		}
		save->left = root->left;
		free(root);
		return right;
	}
}
void main(){
	int i,n;
	printf("\t\t------Enter -1 to break Loop----------\n");
	printf("1.Insertion\n2.PreOrder Traversal\n3.InOrder Traversal\n4.PostOrder Traversal\n.5.Search Operation\n6.Delete Opearation\n\n");
	while(1){
		printf("\nEnter a Operation On BST :");
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		switch(i){
			case 1 : printf("\nEnter Value to Insert:");
			scanf("%d",&n);
			root = insert(n,root);
			break;
			case 2 : printf("\nPreorder Travesal is : ");
			preorder(root);
			break;
			case 3 : printf("\nInorder Travesal is : ");
			inorder(root);
			break;
			case 4 : printf("\nPostorder Travesal is : ");
			postorder(root);
			break;
			case 5 : printf("\nEnter Value to Search in BST:");
			scanf("%d",&n);
			i = search(n,root);
			if(i==0){
				printf("\n%d is not Found in BST.",n);
			}
			else{
				printf("\n%d is Found in BST.",n);
			}
			break;
			case 6 : printf("Enter Node to Delete From Tree:");
			scanf("%d",&n);
			root = deleteNode(n,root);
			break;
		}
	}
	
}
