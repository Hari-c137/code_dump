#include <stdio.h>

#define MAX 100

int adjM[MAX][MAX];
int visitd[MAX];

void dfs(int node, int n) {
  printf("%d", node);
  visitd[node] = 1;

  for (int i = 0; i < n; i++) {
    if (adjM[node][i] == 1 && !visitd[i]) {
      dfs(i,n);
    }
  }
}

int main() {
  int n; 
  printf("enter the number of vertices:");
  scanf("%d", &n);

  printf("enter the adjM:\n");
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adjM[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    visitd[i] = 0;
  }

  int sourcenode;
  printf("enter the source node: ");
  scanf("%d", &sourcenode);

  printf("DFS TRANVERSAL: ");
  dfs(sourcenode, n);

}
