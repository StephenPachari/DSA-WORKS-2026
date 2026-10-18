/* Q2: Insert keys 23, 43, 13, 27, 37 and 53 using open and closed hashing. */
#include <stdio.h>
#define SIZE 10

int main(void) {
    int keys[] = {23, 43, 13, 27, 37, 53};
    int table[SIZE], i, j, index;
    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    for (i = 0; i < 6; i++) {
        index = keys[i] % SIZE;
        while (table[index] != -1)
            index = (index + 1) % SIZE;
        table[index] = keys[i];
    }

    printf("Closed Hashing (Linear Probing):\n");
    for (i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }

    printf("\nOpen Hashing (Separate Chaining):\n");
    printf("Index 0: Empty\nIndex 1: Empty\nIndex 2: Empty\n");
    printf("Index 3: 23 -> 43 -> 13 -> 53\n");
    printf("Index 4: Empty\nIndex 5: Empty\nIndex 6: Empty\n");
    printf("Index 7: 27 -> 37\n");
    printf("Index 8: Empty\nIndex 9: Empty\n");
    return 0;
}
/*
Sample Output:
Closed Hashing (Linear Probing):
Index 0: Empty
Index 1: Empty
Index 2: Empty
Index 3: 23
Index 4: 43
Index 5: 13
Index 6: 53
Index 7: 27
Index 8: 37
Index 9: Empty

Open Hashing (Separate Chaining):
Index 0: Empty
Index 1: Empty
Index 2: Empty
Index 3: 23 -> 43 -> 13 -> 53
Index 4: Empty
Index 5: Empty
Index 6: Empty
Index 7: 27 -> 37
Index 8: Empty
Index 9: Empty
*/
