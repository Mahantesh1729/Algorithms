#include  <stdio.h>

int w[10], x[10], d;

void sum_subset(int s, int k, int r);

//here x[1..,n] is a boolean array to know if a given number is included

int main()
{
    printf("Enter the number of elements: \n");
    int n;
    scanf("%d", &n);

    printf("Enter the elements of the array in the increasing order: \n");

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    printf("Enter the required sum: \n");

    scanf("%d", &d);

    if(sum < d)
    {
        printf("No solution exists!\n");
        return 1;
    }

    printf("The required solution is: \n");

    sum_subset(0, 0, sum);
}

void sum_subset(int s, int k, int r)
{
    int i;
    static int b = 1; //no. of subsets

    x[k] = 1;

    if(s + w[k] == d)
    {
        printf("Subset %d: ", b++);

        for(i = 0; i <= k; i++)
        {
            if(x[i] == 1)
            {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    }
    else if(s + w[k] + w[k + 1] <= d)
    {
        sum_subset(s + w[k], k + 1, r - w[k]);
    }

    if((s + r - w[k] >= d) && (s + w[k + 1]) <= d)
    {
        x[k] = 0;
        sum_subset(s, k + 1, r - w[k]);
    }
}