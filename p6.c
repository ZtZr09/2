#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int top = -1;
int stack[MAX];
void push(int x){
    if(top == MAX-1)
        return;
    stack[++top] = x;
}
int pop(){
    if(top == -1)
        return -1;
    return stack[top--];
}
int isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}
void dfs(int adj[MAX][MAX], int V){
    int visited[MAX] = {0};
    int parent[MAX] = {0};
    push(1);
    visited[1] = 1;
    printf("dfs traversal order:` ");
    while(!isEmpty()){
        int node = pop();
        printf("%d", node);
        for(int i = V;i>=1;i--){
            if(adj[node][i] == 1 && !visited[i]){
                visited[i] = 1;
                push(i);
                parent[i] = node;
            }
        }
    }
    printf("\n dfs spanning tree: ");
    for(int i = 1;i<=V;i++) {
        if(parent[i] != 0)
            printf("%d - %d\n", parent[i], i);
    }
}
int main(){
    int V,E;
    int u,v;
    int adj[MAX][MAX] = {0};
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter each edge (u v) on its own line:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    clock_t start = clock();

    dfs(adj, V);

    clock_t end = clock();
    double time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time used is: %.6f s\n", time_used);

    return 0;
}
