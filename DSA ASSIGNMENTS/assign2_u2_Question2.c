/*
Q.No. 4: A service centre uses a fixed-size request buffer in which released positions must be reused. Write a C program to implement a Circular Queue using an array with insertion, deletion, display, overflow and underflow operations. Demonstrate that positions freed after deletion can be reused for new requests.
*/

#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

void delete() {
    int value;

    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    value = queue[front];
    printf("Deleted: %d\n", value);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
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
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
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
10
1
20
1
30
1
40
1
50
3
2
2
1
60
1
70
3
4

Output:
Inserted: 10
Inserted: 20
Inserted: 30
Inserted: 40
Inserted: 50
Queue: 10 20 30 40 50
Deleted: 10
Deleted: 20
Inserted: 60
Inserted: 70
Queue: 30 40 50 60 70
*/