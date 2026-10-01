/*
Q.No. 10: A transportation network contains cities connected by roads with different costs. Write a C program implementing Dijkstra’s Shortest Path Algorithm that accepts the number of vertices, weighted adjacency matrix and source vertex, computes the minimum distance from the source to every other vertex, and displays each destination with its shortest distance. Test it using at least five vertices.
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int n, graph[100][100];
    int distance[100], visited[100] = {0};
    int source, i, j, min, u;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (i != j && graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }

    scanf("%d", &source);
    source--;

    for (i = 0; i < n; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;

    for (i = 0; i < n - 1; i++) {
        min = INT_MAX;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != INT_MAX &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][j] < distance[j]) {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", source + 1);

    for (i = 0; i < n; i++) {
        if (distance[i] == INT_MAX)
            printf("Vertex %d: INF\n", i + 1);
        else
            printf("Vertex %d: %d\n", i + 1, distance[i]);
    }

    return 0;
}

/*
OUTPUT:

Input:
5
0 10 3 0 0
10 0 1 2 0
3 1 0 8 2
0 2 8 0 7
0 0 2 7 0
1

Output:
Shortest distances from vertex 1:
Vertex 1: 0
Vertex 2: 4
Vertex 3: 3
Vertex 4: 6
Vertex 5: 5
*/