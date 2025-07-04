#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int adj[MAX][MAX] = {0}, visited[MAX] = {0};
int noOfNodes, noOfEdges;

void enqueue(int data) {
  if (rear == MAX - 1) return;
  if (front == -1) front = 0;
  queue[++rear] = data;
}

int dequeue() {
  if (front == -1) return -1;
  int item = queue[front++];
  if (front > rear) front = rear = -1;
  return item;
}

void dfs(int vertex) {
  visited[vertex] = 1;
  printf("%d ", vertex);

  for (int i = 1; i <= noOfNodes; i++) {
    if (adj[vertex][i] == 1 && visited[i] == 0) {
      dfs(i);
    }
  }
}

void bfs(int startVertex) {
  front = rear = -1;
  visited[startVertex] = 1;
  enqueue(startVertex);

  while (front != -1) {
    int vertex = dequeue();
    printf("%d ", vertex);

    for (int i = 1; i <= noOfNodes; i++) {
      if (adj[vertex][i] == 1 && visited[i] == 0) {
        enqueue(i);
        visited[i] = 1;
      }
    }
  }
}

void resetVisited() {
  for (int i = 1; i <= noOfNodes; i++)
    visited[i] = 0;
}

int main() {
  int doRun = 1, choice, startVertex;

  // Get no of nodes and edges from user
  printf("Enter no of nodes: ");
  scanf("%d", &noOfNodes);
  printf("Enter no of edges: ");
  scanf("%d", &noOfEdges);

  // Create an adjacency matrix
  printf("Enter edges as a pair of vertices:\n");
  for (int i = 0; i < noOfEdges; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  printf("\nMENU\n");
  printf("1 - Perform BFS\n");
  printf("2 - Perform DFS\n");
  printf("3 - Exit\n");

  while (doRun) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        resetVisited();
        printf("Enter start vertex: ");
        scanf("%d", &startVertex);
        printf("BFS: ");

        bfs(startVertex);
        for (int i = 1; i <= noOfNodes; i++) 
          if (visited[i] == 0) bfs(i);

        printf("\n");
        break;

      case 2:
        resetVisited();
        printf("Enter start vertex: ");
        scanf("%d", &startVertex);
        printf("DFS: ");

        dfs(startVertex);
        for (int i = 1; i <= noOfNodes; i++) 
          if (visited[i] == 0) dfs(i);

        printf("\n");
        break;
      default:
        printf("\nProgram terminated\n");
        doRun = 0;
    }
  }
  return 0;
}
