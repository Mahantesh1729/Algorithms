#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stck[MAX];
int top = -1;

void push(int);
int pop();
void calc_indegree(int n, int indegree[n], int a[n][n]);

int main()
{
    printf("Enter the number of vertices in the graph:\n");
    int n;
    scanf("%d", &n);
    int a[n][n];

    printf("Enter the adjecency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0;  j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int indegree[n];

    calc_indegree(n, indegree, a);

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            push(i);
        }
    }
    int u;

    // printf("\n\n\n\n");

    // for(int i = 0; i <= top; i++)
    // {
    //     printf("%d ", stck[i]);
    // }

    printf("After topological sort:\n");
    while(top != -1)
    {
        u = pop();

        printf("%d ", u);

        for(int v = 0; v <n; v++)
        {
            if(a[u][v] != 0)
            {
                indegree[v]--;
                if(indegree[v] == 0)
                {
                    push(v);
                }
            }
        }
    }
    printf("\n");



}

void calc_indegree(int n, int indegree[n], int a[n][n])
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += a[j][i];
        }
        indegree[i] = sum;
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
}

void push(int k)
{
    if(top == MAX - 1)
    {
        printf("Overflow!\n");
        exit(0);
    }
    stck[++top] = k;
}
int pop()
{
    return stck[top--];
}