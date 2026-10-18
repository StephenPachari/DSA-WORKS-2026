/* Q8: Demonstrate BST deletion for nodes 10, 20 and 40 separately. */
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

struct Node *minimum(struct Node *root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

struct Node *deleteNode(struct Node *root, int key) {
    struct Node *temp;
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minimum(root->right);
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

void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

struct Node *buildTree(void) {
    int a[] = {40, 20, 60, 10, 30, 50, 70};
    struct Node *root = NULL;
    int i;
    for (i = 0; i < 7; i++)
        root = insert(root, a[i]);
    return root;
}

int main(void) {
    struct Node *root;

    root = buildTree();
    root = deleteNode(root, 10);
    printf("After deleting 10: ");
    inorder(root);
    printf("\n");
    freeTree(root);

    root = buildTree();
    root = deleteNode(root, 20);
    printf("After deleting 20: ");
    inorder(root);
    printf("\n");
    freeTree(root);

    root = buildTree();
    root = deleteNode(root, 40);
    printf("After deleting 40: ");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
/*
Sample Output:
After deleting 10: 20 30 40 50 60 70
After deleting 20: 10 30 40 50 60 70
After deleting 40: 10 20 30 50 60 70
*/
