/*
Q.No. 9: A network of n locations is represented as a graph. Write a C program that accepts the graph using an Adjacency Matrix, accepts a starting vertex, performs a graph traversal, displays the visit order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially connected graphs.
*/

#include <stdio.h>

int main() {
    int n, graph[100][100], visited[100] = {0};
    int queue[100], front = 0, rear = -1;
    int start, i, j, vertex;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    scanf("%d", &start);

    start--;

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS traversal: ");

    while (front <= rear) {
        vertex = queue[front++];
        printf("%d ", vertex + 1);

        for (i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    return 0;
}

/*
OUTPUT:

Input:
5
0 1 1 0 0
1 0 0 1 0
1 0 0 1 1
0 1 1 0 1
0 0 1 1 0
1

Output:
BFS traversal: 1 2 3 4 5


Partially Connected Graph

Input:
5
0 1 0 0 0
1 0 0 0 0
0 0 0 1 0
0 0 1 0 0
0 0 0 0 0
1

Output:
BFS traversal: 1 2
*/