#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void kahns(int v, int adj[v+1][v+1]) {
    int indegree[v+1];
    for (int i = 1; i <= v; i++) {
        indegree[i] = 0;
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    int *q = (int *)malloc(sizeof(int) * v);
    int front = 0, rear = -1;
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q[++rear] = i;
        }
    }

    int *res = (int *)malloc(sizeof(int) * v);
    int index = 0;
    
    while (front <= rear) {
        int node = q[front++];
        res[index++] = node;

        for (int i = 1; i <= v; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q[++rear] = i;
                }
            }
        }
    }

    printf("Topological Order: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(q);
    free(res);
}

int main() {
    clock_t st = clock();

    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    int adj[v + 1][v + 1];
    for (int i = 0; i <= v; i++) {
        for (int j = 0; j <= v; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the pair of edges (u v) in order: ");
    for (int i = 0; i < e; i++) {
        int u, t;
        scanf("%d %d", &u, &t);
        adj[u][t] = 1;
    }

    kahns(v, adj);

    clock_t et = clock();
    double time = ((double)(et - st)) / CLOCKS_PER_SEC;
    printf("Time used is %.6f s\n", time);

    return 0;
}
