#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Global visited array to keep track of nodes
bool visited[MAX];
int adj[MAX][MAX];
int n; // Number of vertices

void dfs(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
    printf("%d ", v);

    // Check all adjacent vertices
    for (int i = 0; i < n; i++) {
        // If there's an edge and the neighbor hasn't been visited
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i); // Recursive call
        }
    }
}

int main() {
    int edges, u, v, startNode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startNode);

    printf("DFS Traversal: ");
    dfs(startNode);
    printf("\n");

    return 0;
}
