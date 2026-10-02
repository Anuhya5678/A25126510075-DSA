
#include <stdio.h>

int graph[20][20];
int visited[20];
int n;

void DFS(int vertex) {
    int i;

    printf("%d ", vertex);

    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 &&
            visited[i] == 0) {

            DFS(i);
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");

    DFS(start);

    return 0;
}