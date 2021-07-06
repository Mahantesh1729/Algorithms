#include <stdio.h>
#include <limits.h>

void dijk(int n, int g[n][n], int start);

#define INF 99999

int main()
{
    printf("Enter the number of vertices: \n");
    int n;
    scanf("%d", &n);
    int g[n][n];

    printf("Enter the adjacency matrix: \n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    printf("Enter the start vertex: ");

    int start;

    scanf("%d", &start);

    dijk(n, g, start);

    return 0;
}

void dijk(int n, int g[n][n], int start)
{
    int cost[n][n];
    int dist[n];
    int visited[n];

    int pred[n];

    int i, j, count, mindist, nextnode;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(g[i][j] == 0)
            {
                cost[i][j] = INF;
            }
            else
            {
                cost[i][j] = g[i][j];
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < n - 1)
    {
        mindist = INF;
        for(i = 0; i < n; i++)
        {
            if(dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if((mindist + cost[nextnode][i]) < dist[i])
                {
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    for(i = 0; i < n; i++)
    {
        if(i != start)
        {
            printf("\nThe distance of node %d is %d\n", i, dist[i]);
            printf("The path is: %d ", i);

            j = i;

            do{
                j = pred[j];
                printf("<- %d ", j);
            }while(j != start);
        }
    }
    printf("\n");
}