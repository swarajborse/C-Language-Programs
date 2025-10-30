#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

int timer = 0;
int disc[MAXN], low[MAXN], parent[MAXN];
bool visited[MAXN], articulation[MAXN];

// Adjacency list representation
int *adj[MAXN];
int adjSize[MAXN];

void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (adjSize[u] + 1) * sizeof(int));
    adj[v] = realloc(adj[v], (adjSize[v] + 1) * sizeof(int));
    adj[u][adjSize[u]++] = v;
    adj[v][adjSize[v]++] = u;
}

void DFS(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            parent[v] = u;
            children++;
            DFS(v);

            // Update low value
            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            // Articulation point check
            if (parent[u] == -1 && children > 1)
                articulation[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
                articulation[u] = true;

            // Bridge check
            if (low[v] > disc[u])
                printf("Bridge: %d - %d\n", u, v);

        } else if (v != parent[u]) {
            // Update low value for back edge
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

void findBridgesAndArticulationPoints(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
        articulation[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            DFS(i);
    }

    printf("\nArticulation Points:\n");
    for (int i = 0; i < n; i++) {
        if (articulation[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        adjSize[i] = 0;
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    findBridgesAndArticulationPoints(n);

    // Free memory
    for (int i = 0; i < n; i++)
        free(adj[i]);

    return 0;
}
