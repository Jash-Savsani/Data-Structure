/* 
The rules of a Red-Black Tree are as follows:
Every node is either red or black.
The root node must be black.
Red nodes cannot have red children (no two consecutive red nodes).
Every leaf (NIL) node is red.
Every path from a node to its descendant NIL nodes must have the same number of black nodes
*/

#include <stdio.h>
#include <stdlib.h>

// Color definitions
#define RED 0
#define BLACK 1

// Node structure
typedef struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
} Node;

// Root pointer
Node* root = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are always RED initially
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;

    if (!y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fix Red-Black Tree violations after insertion
void fixInsert(Node* k) {
    Node* uncle;

    while (k != root && k->parent->color == RED) {
        if (k->parent == k->parent->parent->left) {
            uncle = k->parent->parent->right;

            if (uncle && uncle->color == RED) {
                // Case 1: Uncle is red
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } 
			else {
                // Case 2 and 3
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }

                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        } 
		else {
            uncle = k->parent->parent->left;

            if (uncle && uncle->color == RED) {
                k->parent->color = BLACK;
                uncle->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }

                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }
    }
    
    root->color = BLACK;
}

// Insert a new node into the Red-Black Tree
void insert(int data) {
    Node* node = createNode(data);
    Node* y = NULL;
    Node* x = root;

    while (x != NULL) {
        y = x;
        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;

    if (!y)
        root = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    fixInsert(node);
}

// In-order traversal
void inOrder(Node* node) {
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

// Main function
int main() {
    int nums[] = {10, 20, 30, 15, 25, 5, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
	
	int i;
    for (i = 0; i < n; i++) {
        insert(nums[i]);
    }

    printf("In-order Traversal of Red-Black Tree:\n");
    inOrder(root);
    printf("\n");

    return 0;
}
