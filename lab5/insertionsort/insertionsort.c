#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion_sort(int n, int a[]);
void delay(int num);
int main()
{
    clock_t start, end;
    double cpu_time_used;
    printf("How many elements do you want to enter: ");

    int n;


    scanf("%d", &n);
    int a[n];
    printf("Do you want to enter the elements?\n");
    char c;
    scanf(" %c", &c);

    if(c == 'y' || c == 'Y')
    {
        printf("Enter the elments of the array: ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            a[i] = rand() % (n + 10000);
        }
    }
    start = clock();
    insertion_sort(n, a);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("After sorting: \n");
    for(int i = 0; i < n; i++)
    printf("%d ", a[i]);
    printf("\n");

    printf("\n");
    printf("time taken = %lf seconds\n", cpu_time_used);
}

void insertion_sort(int n, int a[])
{
    int sorted, buffer, j;

    sorted = a[0];

    for(int i = 1; i < n; i++)
    {
        delay(10);
        if(sorted > a[i])
        {
            buffer = a[i];
            for(j = i; j != 0 && a[j - 1] >= buffer; j--)
            {
                delay(10);
                a[j] = a[j - 1];
            }
            a[j] = buffer;
        }
        else
        {
            sorted = a[i];
        }
    }
}
void delay(int num)
{
    int seconds = 1000 * num;

    clock_t start_time = clock();

    while (clock() < start_time + seconds);
}