/*
Q.No. 2: A teacher wants to arrange student marks in ascending order and also measure how much rearrangement is necessary. Write a C program using Insertion Sort that accepts n marks, displays the array after every pass, counts the total number of element shifts, and displays the final sorted list and shift count.
*/

#include <stdio.h>

int main() {
    int n, a[100], i, j, key, shifts = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            shifts++;
        }

        a[j + 1] = key;

        printf("Pass %d: ", i);
        for (j = 0; j < n; j++)
            printf("%d ", a[j]);
        printf("\n");
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal shifts: %d\n", shifts);

    return 0;
}

/*
OUTPUT:

Input:
5
64 34 25 12 22

Output:
Pass 1: 34 64 25 12 22
Pass 2: 25 34 64 12 22
Pass 3: 12 25 34 64 22
Pass 4: 12 22 25 34 64
Sorted array: 12 22 25 34 64
Total shifts: 8
*/