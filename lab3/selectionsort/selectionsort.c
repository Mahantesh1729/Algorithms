#include <stdio.h>
#include <time.h>
void delay(int num);
int main()
{
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int i = 0;
    int smallest, k, index;

    start = clock();
    while(i < n)
    {

        smallest = 99999;

        for(int j = i; j < n; j++)
        {
            delay(100);
            if(a[j] <= smallest)
            {
                smallest = a[j];
                index = j;
            }
        }
        delay(100);
        k = a[i];
        a[i++] = smallest;
        a[index] = k;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("After sorting: \n");

    for(int j = 0; j < n; j++)
    {
        printf(" %d ", a[j]);
    }
    printf("\n");
    printf("time taken = %lf seconds\n", cpu_time_used);
}

void delay(int num)
{
    int seconds = 1000 * num;

    clock_t start_time = clock();

    while (clock() < start_time + seconds);
}