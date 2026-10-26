#include <stdio.h>

#define INF 1000000

int min(int a, int b) {
    return (a < b) ? a : b;
}

void printPath(int V, int parent[], int t, int path_flow) {
    int path[V];
    int path_index = 0;
    int v = t;
    int i;

    while (v != -1) {
        path[path_index++] = v;
        v = parent[v];
    }

    printf("Path: ");
    for (i = path_index - 1; i > 0; i--) {
        printf("v%d -> ", path[i] + 1);
    }
    printf("v%d ", path[0] + 1);
    printf(" Flow: %d\n", path_flow);
}

int bfs(int V, int rGraph[V][V], int s, int t, int parent[]) {
    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int queue[V * V];
    int front = 0, rear = 0;
    int u, v;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        u = queue[front++];

        for (v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                if (v == t) return 1;
                queue[rear++] = v;
                visited[v] = 1;
            }
        }
    }
    return 0;
}

int fordFulkerson(int V, int graph[V][V], int s, int t) {
    int rGraph[V][V];
    int parent[V];
    int max_flow = 0;
    int u, v;

    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }
    while (bfs(V, rGraph, s, t, parent)) {
        int path_flow = INF;

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        printPath(V, parent, t, path_flow);

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    printf("The maximum possible flow is %d\n", max_flow);
    return max_flow;
}

int main() {
    int V;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    int graph[V][V];

    printf("Enter the %d x %d adjacency matrix row by row:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    fordFulkerson(V, graph, 0, V - 1);
    return 0;
}
