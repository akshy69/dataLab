#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int node) {
  int i;
  printf("%d ", node);
  visited[node] = 1;
  for (i = 0; i < n; i++) {
    if (adj[node][i] == 1 && !visited[i]) {
      dfs(i);
    }
  }
}

void readGraph() {
  int i, j;
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  printf("Enter adjacency matrix: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }
}

int main() {
  int start;
  readGraph();
  printf("Enter start node: ");
  scanf("%d", &start);
  printf("Depth-First Search: ");
  dfs(start);
  return 0;
}