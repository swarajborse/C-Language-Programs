#include <stdio.h>
#include <stdlib.h>

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    int* arr;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = n;
    q->arr = (int*)malloc(n * sizeof(int));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, int val) {
    q->arr[q->rear++] = val;
}

int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Function for Topological Sort (BFS)
void topoSortBFS(int n, int m, int adj[n][n]) {
    int indegree[n];
    for (int i = 0; i < n; i++) indegree[i] = 0;

    // Calculate indegree
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) indegree[v]++;
        }
    }

    struct Queue* q = createQueue(n);

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(q, i);
    }

    int count = 0;
    int topo[n];

    while (!isEmpty(q)) {
        int node = dequeue(q);
        topo[count++] = node;

        // Decrease indegree of neighbours
        for (int v = 0; v < n; v++) {
            if (adj[node][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(q, v);
            }
        }
    }

    // Print result
    if (count != n) {
        printf("Graph has a cycle, topological order not possible.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", topo[i]);
    printf("\n");
}

int main() {
    int n, m;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v) for directed edges u -> v:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSortBFS(n, m, adj);
    return 0;
}
