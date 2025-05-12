#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int x){
    if(front== -1)
        front = 0;
    if(rear == MAX-1)
        return;
    queue[++rear] = x;
}
int dequeue(){
    if(front == -1|| front > rear)
        return -1;
    return queue[front++];
}
int isEmpty(){
    if (front == -1|| front >rear)
        return 1;
    return 0;
}
void bfs(int V, int adj[MAX][MAX], int start){
    int visited[MAX] = {0};
    int parent[MAX] = {0};
    enqueue(start);
    visited[start] = 1;
    while(!isEmpty()){
        int node = dequeue();
        printf("%d", node);
        for(int i = 0;i<=V;i++){
            if(adj[node][i]==1 && !visited[i]){
                visited[i] = 1;
                enqueue(i);
                parent[i] = node;
            }
        }
    }
    printf("BST TREE\n");
    for (int i = 0;i<=V;i++){
        if(parent[i] != 0)
            printf("%d - %d\n", parent[i],i);
    }
}
int main(){
    int V,E,u,v;
    printf("Enter the number of vertices and edges");
    scanf("%d", &V);
    scanf("%d", &E);
    printf("Enter the vertices-> vertices");
    int adj[MAX][MAX] = {0};
    for(int i = 0;i<E;i++){
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    clock_t st, et;
    st = clock();
    bfs(V, adj, 1);
    et = clock();
    double tt = ((double)(et-st))/CLOCKS_PER_SEC;
    printf("TT: %f", tt);
}
