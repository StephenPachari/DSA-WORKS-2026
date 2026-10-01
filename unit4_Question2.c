/*
Q.No. 8: Extend a Binary Search Tree program to support deletion. The program should create a BST, delete a user-specified node, correctly handle nodes with zero, one and two children, and display inorder traversal before and after deletion. Test the program separately for all three deletion cases.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, int value) {
    struct Node *temp;

    if (root == NULL)
        return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int n, value, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder before deletion: ");
    inorder(root);

    scanf("%d", &value);

    root = deleteNode(root, value);

    printf("\nInorder after deletion: ");
    inorder(root);

    return 0;
}

/*
OUTPUT:

Test 1 - Leaf Node

Input:
7
50 30 70 20 40 60 80
20

Output:
Inorder before deletion: 20 30 40 50 60 70 80
Inorder after deletion: 30 40 50 60 70 80


Test 2 - Node with One Child

Input:
6
50 30 70 20 60 80
30

Output:
Inorder before deletion: 20 30 50 60 70 80
Inorder after deletion: 20 50 60 70 80


Test 3 - Node with Two Children

Input:
7
50 30 70 20 40 60 80
50

Output:
Inorder before deletion: 20 30 40 50 60 70 80
Inorder after deletion: 20 30 40 60 70 80
*/