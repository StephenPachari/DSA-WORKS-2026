/* Q5: Compare array and singly linked list operations for a 500-song playlist. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int song;
    struct Node *next;
};

int main(void) {
    struct Node *head = NULL, *tail = NULL, *newNode, *temp;
    int i;

    for (i = 1; i <= 5; i++) {
        newNode = malloc(sizeof(struct Node));
        if (newNode == NULL) return 1;
        newNode->song = i * 100;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }

    printf("Playlist: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->song);

    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) return 1;
    newNode->song = 250;
    newNode->next = head->next;
    head->next = newNode;

    printf("\nAfter inserting 250: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->song);

    temp = head;
    head = head->next;
    free(temp);

    printf("\nAfter deleting first song: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->song);

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n");
    return 0;
}
/*
Sample Output:
Playlist: 100 200 300 400 500
After inserting 250: 100 250 200 300 400 500
After deleting first song: 250 200 300 400 500
*/