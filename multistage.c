#include <stdio.h>
#define INF 9999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    int dist[n];
    int path[n];

    dist[n-1] = 0;

    for(int i = n-2; i >= 0; i--) {
        dist[i] = INF;
        for(int j = i+1; j < n; j++) {
            if(cost[i][j] != INF && cost[i][j] + dist[j] < dist[i]) {
                dist[i] = cost[i][j] + dist[j];
                path[i] = j;
            }
        }
    }

    printf("Minimum cost = %d\n", dist[0]);

    printf("Path: 0 ");
    int i = 0;
    while(i != n-1) {
        i = path[i];
        printf("-> %d ", i);
    }

    return 0;
}
