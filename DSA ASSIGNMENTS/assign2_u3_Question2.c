/*
Q.No. 6: Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a user. The program should insert a new page, move forward and backward, delete a specified page, and display the pages from first-to-last and last-to-first while handling beginning and end conditions correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void insert(char page[]) {
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp;

    strcpy(newNode->page, page);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void forward() {
    if (current == NULL) {
        printf("No pages available\n");
    } else if (current->next == NULL) {
        printf("Already at the last page: %s\n", current->page);
    } else {
        current = current->next;
        printf("Current page: %s\n", current->page);
    }
}

void backward() {
    if (current == NULL) {
        printf("No pages available\n");
    } else if (current->prev == NULL) {
        printf("Already at the first page: %s\n", current->page);
    } else {
        current = current->prev;
        printf("Current page: %s\n", current->page);
    }
}

void deletePage(char page[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Page not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);
    printf("Page deleted\n");
}

void displayForward() {
    struct Node *temp = head;

    printf("First to last: ");

    while (temp != NULL) {
        printf("%s ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

void displayBackward() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Last to first: ");

    while (temp != NULL) {
        printf("%s ", temp->page);
        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    int choice;
    char page[50];

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%s", page);
                insert(page);
                break;

            case 2:
                forward();
                break;

            case 3:
                backward();
                break;

            case 4:
                scanf("%s", page);
                deletePage(page);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
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
Google
1
YouTube
1
GitHub
5
6
2
2
3
4
YouTube
5
6
7

Output:
First to last: Google YouTube GitHub
Last to first: GitHub YouTube Google
Current page: YouTube
Current page: GitHub
Current page: YouTube
Page deleted
First to last: Google GitHub
Last to first: GitHub Google
*/