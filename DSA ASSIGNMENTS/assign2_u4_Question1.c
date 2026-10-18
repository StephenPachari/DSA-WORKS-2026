/*
Q.No. 7: A system stores unique integer identification numbers using a Binary Search Tree. Write a C program to insert n values, display inorder, preorder and postorder traversals, search for a specified value, and report whether it exists. Use the output to explain why inorder traversal produces sorted values.
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

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct Node *root, int value) {
    if (root == NULL)
        return 0;

    if (root->data == value)
        return 1;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

int main() {
    struct Node *root = NULL;
    int n, value, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &value);

    if (search(root, value))
        printf("Value exists\n");
    else
        printf("Value does not exist\n");

    return 0;
}

/*
OUTPUT:

Input:
7
50 30 70 20 40 60 80
40

Output:
Inorder: 20 30 40 50 60 70 80
Preorder: 50 30 20 40 70 60 80
Postorder: 20 40 30 60 80 70 50
Enter value to search: 40
Value exists

The inorder traversal produces sorted values because smaller values
are stored in the left subtree and larger values are stored in the
right subtree.
*/