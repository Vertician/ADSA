
#include <stdio.h>

#define INF 99999

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, source;
    struct Edge edge[100];
    int dist[100];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter source, destination and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
            &edge[i].src,
            &edge[i].dest,
            &edge[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Step 1: Initialization
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative-weight cycle
    for (int i = 0; i < E; i++) {
        int u = edge[i].src;
        int v = edge[i].dest;
        int w = edge[i].weight;

        if (dist[u] != INF &&
            dist[u] + w < dist[v]) {
            printf("Negative weight cycle exists.\n");
            return 0;
        }
    }

    // Step 4: Display shortest distances
    printf("\nVertex\tDistance from Source\n");

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
