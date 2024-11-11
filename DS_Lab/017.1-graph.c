#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];
int stack[MAX], top = -1;
int queue[MAX], front = -1, rear = -1;

void push(int data) {
  if (top == MAX - 1) {
    printf("Stack Overflow\n");
    exit(EXIT_FAILURE);
  }
  stack[++top] = data;
}

int pop() {
  if (top == -1) {
    printf("Stack Underflow\n");
    exit(EXIT_FAILURE);
  }
  return stack[top--];
}

void enqueue(int data) {
  if (rear == MAX - 1) {
    printf("Queue Overflow\n");
    exit(EXIT_FAILURE);
  }
  if (front == -1) front = 0;
  queue[++rear] = data;
}

int dequeue() {
  if (front == -1) {
    printf("Queue Underflow\n");
    exit(EXIT_FAILURE);
  }
  int item = queue[front];
  if (front == rear) front = rear = -1;
  else front++;
  return item;
}

void bfs(int startVertex, int vertices) {
  for (int i = 0; i <= vertices; i ++) visited[i] = 0;

  enqueue(startVertex);
  visited[startVertex] = 1;

  printf("BFS: ");
  while (front != -1) {
    int currVertex = dequeue();
    printf("%d ", currVertex);
    for (int i = 1; i <= vertices; i++)
      if (adj[currVertex][i] && !visited[i]) {
        enqueue(i);
        visited[i] = 1;
      }
  }
  printf("\n");
}

void dfs(int startVertex, int vertices) {
  for (int i = 0; i <= vertices; i++) visited[i] = 0;
  push(startVertex);

  printf("DFS: ");
  while (top != -1) {
    int currVertex = pop();
    if (!visited[currVertex]) {
      printf("%d ", currVertex);
      visited[currVertex] = 1;
    }
    for (int i = vertices; i >= 1; i--) {
      if (adj[currVertex][i] && !visited[i]) {
        push(i);
      }
    }
  }
  printf("\n");
}

int main() {
  int vertices, edges, doRun = 1, choice, startVertex;
  printf("Enter no of vertices: ");
  scanf("%d", &vertices);
  printf("Enter no of edges: ");
  scanf("%d", &edges);

  printf("\nEnter Edges:\n");
  for (int i = 0; i < edges; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  
  printf("\n1 - Perform BFS\n");
  printf("2 - Perform DFS\n");
  printf("3 - Exit\n");

  while (doRun) {
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter starting vertex: ");
        scanf("%d", &startVertex);
        bfs(startVertex, vertices);
        for (int i = 1; i <= vertices; i++)
          if (!visited[i])
            bfs(i, vertices);
        break;
      case 2:
        printf("Enter starting vertex: ");
        scanf("%d", &startVertex);
        dfs(startVertex, vertices);
        for (int i = 1; i <= vertices; i++) 
          if (!visited[i])
            dfs(i, vertices);
        break;
      default:
        doRun = 0;
        printf("Program Terminated");
    }
  }
}

