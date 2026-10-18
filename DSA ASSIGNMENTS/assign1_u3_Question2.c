/* Q6: Implement a doubly linked list for forward and backward passenger navigation. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int passenger;
    struct Node *prev;
    struct Node *next;
};

int main(void) {
    struct Node *head = NULL, *tail = NULL, *node, *current;
    int values[] = {101, 102, 103, 104};
    int i;

    for (i = 0; i < 4; i++) {
        node = malloc(sizeof(struct Node));
        if (node == NULL) return 1;
        node->passenger = values[i];
        node->next = NULL;
        node->prev = tail;
        if (tail != NULL)
            tail->next = node;
        else
            head = node;
        tail = node;
    }

    printf("Forward: ");
    for (current = head; current != NULL; current = current->next)
        printf("%d ", current->passenger);

    printf("\nBackward: ");
    for (current = tail; current != NULL; current = current->prev)
        printf("%d ", current->passenger);

    current = head->next;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);

    printf("\nAfter deleting passenger 102, forward: ");
    for (current = head; current != NULL; current = current->next)
        printf("%d ", current->passenger);

    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
    printf("\n");
    return 0;
}
/*
Sample Output:
Forward: 101 102 103 104
Backward: 104 103 102 101
After deleting passenger 102, forward: 101 103 104
*/
