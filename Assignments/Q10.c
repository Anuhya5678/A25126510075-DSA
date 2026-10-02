
#include <stdio.h>

#define INF 99999

int main() {
    int n;
    int graph[20][20];
    int distance[20];
    int visited[20];
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    printf("Enter 0 if there is no edge\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (int i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {

        int min = INF;
        int u = -1;

        /* Find minimum distance vertex */
        for (int i = 0; i < n; i++) {

            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        /* Update distances */
        for (int v = 0; v < n; v++) {

            if (!visited[v] &&
                graph[u][v] != INF &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] =
                    distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (int i = 0; i < n; i++) {

        if (distance[i] == INF)
            printf("Vertex %d : Not reachable\n", i);
        else
            printf("Vertex %d : %d\n", i, distance[i]);
    }

    return 0;
}