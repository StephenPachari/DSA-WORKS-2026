/*
Q.No. 1: A company stores employee IDs in ascending order. Write a C program that accepts n employee IDs, searches for a required ID using Binary Search, displays its position when found, reports when it is absent, and counts the number of comparisons. Test the program for both successful and unsuccessful searches.
*/

#include <stdio.h>

int main() {
    int n, a[100], key;
    int low, high, mid, comparisons = 0, position = -1;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;

        if (a[mid] == key) {
            position = mid;
            break;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (position != -1)
        printf("Employee ID found at position %d\n", position + 1);
    else
        printf("Employee ID not found\n");

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}

/*
OUTPUT:

Input:
6
101 105 110 115 120 125
115

Output:
Employee ID found at position 4
Number of comparisons: 2

Input:
6
101 105 110 115 120 125
118

Output:
Employee ID not found
Number of comparisons: 3
*/