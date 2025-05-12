#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int top = -1;
int stack[MAX];

void push(int x) {
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}

int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void dfsTopo(int node, int adj[MAX][MAX], int visited[MAX], int V) {
    visited[node] = 1;
    for (int i = 1; i <= V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfsTopo(i, adj, visited, V);
        }
    }
    push(node); // Post-order push for topo sort
}

void topologicalSort(int adj[MAX][MAX], int V) {
    int visited[MAX] = {0};

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            dfsTopo(i, adj, visited, V);
        }
    }

    printf("Topological Sort Order: ");
    while (!isEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int V, E;
    int u, v;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter each edge (u v) on its own line:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge u → v
    }

    clock_t start = clock();

    topologicalSort(adj, V);

    clock_t end = clock();
    double time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time used is: %.6f s\n", time_used);

    return 0;
}
