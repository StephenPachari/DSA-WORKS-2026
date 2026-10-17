/* Q10: Apply Dijkstra's Algorithm to find shortest paths from vertex A. */
#include <stdio.h>
#define V 5
#define INF 99999

int main(void) {
    int graph[V][V] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };
    int dist[V], visited[V] = {0};
    int i, j, u, min;

    for (i = 0; i < V; i++)
        dist[i] = INF;
    dist[0] = 0;

    for (i = 0; i < V - 1; i++) {
        min = INF;
        u = -1;
        for (j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        for (j = 0; j < V; j++) {
            if (!visited[j] && graph[u][j] != 0 &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }

        printf("After selecting %c: ", 'A' + u);
        for (j = 0; j < V; j++) {
            if (dist[j] == INF)
                printf("%c=INF ", 'A' + j);
            else
                printf("%c=%d ", 'A' + j, dist[j]);
        }
        printf("\n");
    }

    printf("\nFinal shortest distances from A:\n");
    for (i = 0; i < V; i++)
        printf("A to %c = %d\n", 'A' + i, dist[i]);
    return 0;
}
/*
Sample Output:
After selecting A: A=0 B=4 C=2 D=INF E=INF
After selecting C: A=0 B=3 C=2 D=10 E=12
After selecting B: A=0 B=3 C=2 D=8 E=12
After selecting D: A=0 B=3 C=2 D=8 E=10

Final shortest distances from A:
A to A = 0
A to B = 3
A to C = 2
A to D = 8
A to E = 10
*/
