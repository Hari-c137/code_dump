#include <stdio.h>

#define MAX 100

int adjM[MAX][MAX], visitd[MAX];

void dfs(int node, int n) {
    printf("%d ", node);
    visitd[node] = 1;
    for (int i = 0; i < n; i++)
        if (adjM[node][i] && !visitd[i]) dfs(i, n);
}

int main() {
    int n, sourcenode;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &adjM[i][j]);
    for (int i = 0; i < n; i++) visitd[i] = 0;
    printf("Enter source node: ");
    scanf("%d", &sourcenode);
    printf("DFS Traversal: ");
    dfs(sourcenode, n);
    printf("\n");
    return 0;
}

