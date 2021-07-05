#include <stdio.h>
#include <limits.h>

void kruskal(int n, int arr[n][n]);

int main()
{
    int n;
    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    int arr[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    kruskal(n,arr);
}

void kruskal(int n, int arr[n][n])
{
    int parent[n];

    for(int i = 0; i < n; i++)
    {
        parent[i] = 0;
    }

    int twg = 0;
    int u, v, a, b;
    int min;
    for(int nodes = 0; nodes < n; nodes++)
    {
        min = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j] < min)
                {
                    min = arr[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        while(parent[u] != 0)
        {
            u = parent[u];
        }
        while(parent[v] != 0)
        {
            v = parent[v];
        }

        if(u != v)
        {

            printf("%d----->%d w = %d\n", a, b, min);
            parent[v] = u;
            twg += min;
        }
        arr[a][b] = INT_MAX;
        arr[b][a] = INT_MAX;

    }

    printf("The minimum cost of this minimum spanning tree is %d\n", twg);
}