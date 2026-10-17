/* Q7: Construct a BST from 50, 30, 70, 20, 40, 60, 80 and display traversals. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        root = malloc(sizeof(struct Node));
        if (root == NULL) exit(1);
        root->data = value;
        root->left = root->right = NULL;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
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

int main(void) {
    struct Node *root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    for (i = 0; i < 7; i++)
        root = insert(root, a[i]);

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
/*
Sample Output:
Inorder: 20 30 40 50 60 70 80
Preorder: 50 30 20 40 70 60 80
Postorder: 20 40 30 60 80 70 50
*/
