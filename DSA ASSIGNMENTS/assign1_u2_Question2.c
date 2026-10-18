/* Q4: Demonstrate how a circular queue of size 5 reuses empty positions. */
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue(void) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display(void) {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    enqueue(60);
    enqueue(70);
    display();
    return 0;
}
/*
Sample Output:
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
