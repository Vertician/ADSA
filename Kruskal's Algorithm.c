
#include <stdio.h>

int parent[10],rank[10];
int G[10][10],edge[10][3];
int V,E=0;
int totalcost=0;

struct edge
{
    int u,v,w;
};

struct edge edgetable[10];

void readGraph()
{
    printf("\nEnter adjacency matrix row by row:\n");

    for(int i = 0; i < V; i++)
    {
        printf("Enter row %d: ", i);

        for(int j = 0; j < V; j++)
        {
            scanf("%d",&G[i][j]);

            if(G[i][j] !=0 && i<j)
                E++;
        }
    }
}

void displaygraph()
{
    printf("\nGraph is...\n");

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            printf("%d\t",G[i][j]);
        }
        printf("\n");
    }
}

void print1Darray(char *str,int a[])
{
    printf("\n%s [] : ",str);

    for(int i = 0; i < V; i++)
    {
        printf("\t%d",a[i]);
    }
}

void makeset(int x)
{
    parent[x] = x;
    rank[x] = 0;
}

void createtable()
{
    int k = 0;

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(G[i][j] != 0 && i < j)
            {
                edgetable[k].u = i;
                edgetable[k].v = j;
                edgetable[k].w = G[i][j];
                k++;
            }
        }
    }
}

void printEdgeTable()
{
    printf("\nEdge table\n");

    for(int i = 0; i < E; i++)
    {
        printf("%d --> %d : %d\n",
               edgetable[i].u,
               edgetable[i].v,
               edgetable[i].w);
    }
}

void bubbleSort()
{
    int i, j;

    for(i = 0; i < E-1; i++)
    {
        for(j = 0; j < E-i-1; j++)
        {
            if(edgetable[j].w > edgetable[j+1].w)
            {
                struct edge temp = edgetable[j];
                edgetable[j] = edgetable[j+1];
                edgetable[j+1] = temp;
            }
        }
    }
}

int findset(int x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);

    return parent[x];
}

void link(int x,int y)
{
    if(rank[x] > rank[y])
        parent[y] = x;
    else
    {
        parent[x] = y;

        if(rank[x] == rank[y])
            rank[y] += 1;
    }
}

void unionop(int x,int y)
{
    link(findset(x),findset(y));
}

int main()
{
    printf("\nEnter number of vertices\n");
    scanf("%d",&V);

    if(V < 1 || V > 10)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    readGraph();
    displaygraph();

    printf("No.of vertex : %d\nNo.of Edges : %d\n",V,E);

    for(int i = 0; i < V; i++)
    {
        makeset(i);
    }

    createtable();

    printf("\n\nEdge table before Sorting\n");
    printEdgeTable();

    bubbleSort();

    printf("\n\nEdge table after Sorting\n");
    printEdgeTable();

    for(int i = 0; i < E; i++)
    {
        if(findset(edgetable[i].u) != findset(edgetable[i].v))
        {
            unionop(edgetable[i].u,edgetable[i].v);

            totalcost += edgetable[i].w;

            printf("\n\nEdges (%d,%d) : %d",
                   edgetable[i].u,
                   edgetable[i].v,
                   edgetable[i].w);
        }
    }

    print1Darray("\nparent array",parent);
    print1Darray("rank array",rank);

    printf("\n\nTotal Cost : %d\n",totalcost);

    return 0;
}
