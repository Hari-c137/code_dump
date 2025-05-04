#include <stdio.h>

#define MAX 100

int adj[MAX][MAX] = {0}; // Adjacency matrix
int visited[MAX] = {0};  // Visited array
int queue[MAX];          // Queue for BFS
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void BFS(int start, int n) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, edges, x, y, start;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    printf("Enter edges (format: u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &x, &y);
        if (x >= 0 && x < n && y >= 0 && y < n)
            adj[x][y] = adj[y][x] = 1;
        else
            printf("Invalid edge: %d %d\n", x, y);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start, n);

    return 0;
}

