#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements in the array:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int swapped;
    int k;
    int last = n;

    start = clock();
    do{
        swapped = 0;
        for(int i = 0; i < last - 1; i++)
        {
            if(a[i] > a[i + 1])
            {
                k = a[i];
                a[i] = a[i + 1];
                a[i + 1] = k;
                swapped = 1;
            }
        }
        last--;
    }while(swapped);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("After sorting: \n");
    for(int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
    printf("time taken = %lf seconds\n", cpu_time_used);
}