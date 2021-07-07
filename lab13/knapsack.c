#include <stdio.h>

void knapsack();
int max(int x,int y);

int i, j, n, m, p[10], w[10], v[10][10];

int main()
{

    printf("Enter the number of objects: \n");
    scanf("%d", &n);

    printf("Enter the weights of each object: \n");

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }


    p[0] = 0;

    printf("Enter the profit of each object: \n");

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter the capacity of the knapsack: \n");



    scanf("%d", &m);

    knapsack();
}

void knapsack()
{
    int x[10];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if(j - w[i] < 0)
            {
                v[i][j] = v[i - 1][j];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }


    printf("\n The output is: \n");
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    printf("The optimal solution is %d\n", v[n][m]);

    printf("The solution vector is : \n");

    for(i = n; i >= 1; i--)
    {
        if(v[i][m] != v[i - 1][m])
        {
            x[i] = 1;
            m = m - w[i];
        }
        else
        {
            x[i] = 0;
        }
    }
    for(i = 1; i <= n; i++)
    {
        printf("%d\t", x[i]);
    }
    printf("\n");
}

int max(int x,int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}