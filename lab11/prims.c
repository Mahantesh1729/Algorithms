#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

void print(int n , int parent[n], int a[n][n])
{
    printf("Parent child weight\n");
    int weight = 0;
    for(int i = 0; i < n; i++)
    {
        weight += a[parent[i]][i];
        printf("%d---->%d = %d\n", parent[i], i, a[parent[i]][i]);
    }
    printf("Weight of the minimum spanning tree is %d\n", weight);
}

int minKey(int n, int key[n], bool mstSet[n])
{
    int min = INT_MAX;
    int min_index;
    for(int i = 0; i < n; i++)
    {
        if(mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;
    }
    return min_index;
}

void prims(int n, int a[n][n])
{
    int parent[n];
    int key[n];
    bool mstSet[n];
    int u;
    for(int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;

    parent[0] = -1;

    for(int i = 0; i < n - 1; i++)
    {
        u = minKey(n, key, mstSet);
        mstSet[u] = true;

        for(int v = 0; v < n; v++)
        {
            if(a[u][v] && mstSet[v] == false && a[u][v] < key[v])
            {
                parent[v] = u, key[v] = a[u][v];
            }
        }
    }

    print(n , parent, a);
}



int main()
{
    printf("Enter the value of n\n");

    int n;

    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");

    int a[n][n];

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    prims(n, a);
}