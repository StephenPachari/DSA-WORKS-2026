/*
Q.No. 5: A department maintains student roll numbers dynamically. Write a C program using a Singly Linked List to create the list, insert at the beginning and end, search for a specified roll number, delete a specified roll number, and display the updated list after each operation. Handle the case when a requested roll number is not available.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void search(int value) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Roll number %d found\n", value);
            return;
        }
        temp = temp->next;
    }

    printf("Roll number %d not found\n", value);
}

void deleteNode(int value) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number %d not found\n", value);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Roll number %d deleted\n", value);
}

void display() {
    struct Node *temp = head;

    printf("List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                insertBeginning(value);
                display();
                break;

            case 2:
                scanf("%d", &value);
                insertEnd(value);
                display();
                break;

            case 3:
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                scanf("%d", &value);
                deleteNode(value);
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/*
OUTPUT:

Input:
1
20
1
10
2
30
5
3
20
4
10
5
3
50
6

Output:
List: 20
List: 10 20
List: 10 20 30
List: 10 20 30
Roll number 20 found
Roll number 10 deleted
List: 20 30
List: 20 30
Roll number 50 not found
*/