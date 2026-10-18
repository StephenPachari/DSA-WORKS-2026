/* Q1: Compare Sequential Search and Binary Search for 10,000 sorted student roll numbers. */
#include <stdio.h>

int sequentialSearch(int a[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(void) {
    int a[10000], i, key = 8765, s, b;
    for (i = 0; i < 10000; i++)
        a[i] = i + 1;

    s = sequentialSearch(a, 10000, key);
    b = binarySearch(a, 10000, key);

    printf("Sequential Search: position = %d\n", s + 1);
    printf("Binary Search: position = %d\n", b + 1);
    printf("Sequential Search comparisons: %d\n", s + 1);
    printf("Binary Search comparisons: about 14\n");
    return 0;
}
/*
Sample Output:
Sequential Search: position = 8765
Binary Search: position = 8765
Sequential Search comparisons: 8765
Binary Search comparisons: about 14
*/