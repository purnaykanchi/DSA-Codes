#include <stdio.h>
#define MAX_NODES 100

void DFS(int graph[MAX_NODES][MAX_NODES], int start, int nodes, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < nodes; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, i, nodes, visited);
        }
    }
}

int main() {
    int nodes, edges, i, j;
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);
    int visited[MAX_NODES] = {0};
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);
    printf("Depth First Search starting from node %d: ", startNode);
    DFS(graph, startNode, nodes, visited);
    return 0;
}