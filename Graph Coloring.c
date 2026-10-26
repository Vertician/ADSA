
#include <stdio.h>

int graph[20][20], color[20];
int N, M, totalSolutions = 0;

int isSafe(int vertex, int c)
{
    int i;

    for (i = 0; i < N; i++)
    {
        if (graph[vertex][i] == 1 && color[i] == c)
            return 0;
    }

    return 1;
}

void graphColoring(int vertex)
{
    int c, i;

    if (vertex == N)
    {
        totalSolutions++;

        printf("Solution %d: ", totalSolutions);

        for (i = 0; i < N; i++)
            printf("%d ", color[i]);

        printf("\n");
        return;
    }

    for (c = 1; c <= M; c++)
    {
        if (isSafe(vertex, c))
        {
            color[vertex] = c;

            graphColoring(vertex + 1);

            /* Backtracking */
            color[vertex] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &N);

    if (N <= 0 || N > 20)
    {
        printf("Enter N between 1 and 20.\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter number of colors: ");
    scanf("%d", &M);

    if (M <= 0)
    {
        printf("Number of colors must be positive.\n");
        return 1;
    }

    printf("\nValid color assignments:\n");

    graphColoring(0);

    if (totalSolutions == 0)
        printf("No coloring possible.\n");

    printf("Total Solutions: %d\n", totalSolutions);

    return 0;
}
