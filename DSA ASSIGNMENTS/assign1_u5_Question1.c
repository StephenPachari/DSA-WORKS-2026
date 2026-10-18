/* Q9: Represent a six-building campus network using an adjacency matrix and adjacency list. */
#include <stdio.h>
#define V 6

int main(void) {
    int graph[V][V] = {0};
    int edges[][2] = {{0,1},{0,2},{1,3},{2,3},{3,4},{4,5}};
    int degree[V] = {0};
    int adj[V][V];
    int i, j, u, v;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            adj[i][j] = -1;

    for (i = 0; i < 6; i++) {
        u = edges[i][0];
        v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    printf("Adjacency Matrix:\n  A B C D E F\n");
    for (i = 0; i < V; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for (i = 0; i < V; i++) {
        printf("%c: ", 'A' + i);
        for (j = 0; j < degree[i]; j++)
            printf("%c ", 'A' + adj[i][j]);
        printf("\n");
    }
    return 0;
}
/*
Sample Output:
Adjacency Matrix:
  A B C D E F
A 0 1 1 0 0 0
B 1 0 0 1 0 0
C 1 0 0 1 0 0
D 0 1 1 0 1 0
E 0 0 0 1 0 1
F 0 0 0 0 1 0

Adjacency List:
A: B C
B: A D
C: A D
D: B C E
E: D F
F: E
*/