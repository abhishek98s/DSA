#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = NULL;
    
    // Insert nodes into the tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    
    // Perform traversals
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    return 0;
}