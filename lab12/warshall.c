#include <stdio.h>

void warshall(int n, int adj[n][n]);
void display(int n, int path[n][n]);

int main()
{
    printf("Enter the number of vertices: \n");
    int n;
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");

    int adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    warshall(n, adj);
}

void warshall(int n, int adj[n][n])
{
    int path[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            path[i][j] = adj[i][j];
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }

    display(n, path);
}

void display(int n, int path[n][n])
{
    printf("The required path matrix is: \n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");

    }
}