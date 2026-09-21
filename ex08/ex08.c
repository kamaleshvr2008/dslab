#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 10
#define INFINITY 999
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src)
{
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INFINITY;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; ++count)
    {
        int u = -1;
        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] &&
                (u == -1 || dist[v] < dist[u]))
            {
                u = v;
            }
        }
        if (u == -1 || dist[u] == INFINITY)
        {
            break;
        }
        visited[u] = 1;
        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] &&
                graph[u][v] != INFINITY &&
                dist[u] != INFINITY &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("\nShortest Paths from Source Vertex %d:\n", src);
    for (int i = 0; i < n; ++i)
    {
        if (i != src)
        {
            if (dist[i] == INFINITY)
            {
                printf("Path to vertex %d: Unreachable\n", i);
            }
            else
            {
                printf("Path to vertex %d: Cost = %d | Path = %d",
                       i, dist[i], i);
                int p = parent[i];

                while (p != -1)
                {
                    printf(" <- %d", p);
                    p = parent[p];
                }

                printf("\n");
            }
        }
    }
}
int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_VERTICES)
    {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    printf("\nEnter the cost adjacency matrix\n");
    printf("(Enter %d for no direct path):\n", INFINITY);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
            {
                graph[i][j] = INFINITY;
            }
        }
    }
    printf("\nEnter the source vertex (starting from 0): ");
    scanf("%d", &src);
    if (src < 0 || src >= n)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }
    dijkstra(graph, n, src);
    return 0;
}                                                  
