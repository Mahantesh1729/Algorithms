#include <stdio.h>

#define Inf 99999

void floyd(int n, int cost[n][n]);
int min(int a, int b);
void print(int n, int cost[n][n]);


int main()
{
    int n;

    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter the cost matrix: \n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
            {
                cost[i][j] = Inf;
            }
        }

    }

    floyd(n, cost);

    print(n, cost);
}

void floyd(int n, int cost[n][n])
{

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}


int min(int a, int b)
{
    return a < b ? a : b;
}

void print(int n, int cost[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}