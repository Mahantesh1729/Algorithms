#include <stdio.h>
#define MAX 10
int stck[MAX];
int t = -1;
void traverse(int cost[10][10], int n);
void dfs(int n, int cost[10][10], int u, int s[]);
void push(int k);
int main()
{
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    int cost[10][10];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Graph traversal:\n");
    int con = 0;
    int s[10];
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            s[j] = 0;

        dfs(n, cost, i, s);
        flag = 0;

        for(int j = 0; j < n; j++)
        {
            if(s[j] == 0)
                flag = 1;
        }
        if(flag == 0)
            con = 1;
    }
    if (con == 1)
    {
        for(int i = 0; i < n; i++)
        {
            printf(" %d ", stck [i]);
        }
        printf("\nGraph is connected\n");
    }

    else
    {

        printf("NULL\n");
        printf("Graph is not connected\n");
    }

}

void dfs(int n, int cost[10][10], int u, int s[])
{
    int v;
    s[u] = 1;
    push(u);
    for( v = 0; v < n; v++)
    {
        if(cost[u][v] == 1 && s[v] == 0)
            {
                dfs(n, cost, v, s);
            }
    }

}

void push(int k)
{
    for(int i = 0; i < t; i++)
    {
        if(stck[i] == k)
        {
            return;
        }
    }
    stck[++t] = k;
}
