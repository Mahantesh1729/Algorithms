#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quicksort(int low, int high, int a[]);
int partition(int low, int high, int a[]);
void delay(int num);
int main()
{
    char c;
    clock_t start, end;
    double cpu_time_used;
   printf("Do you want to enter them manually?\n");
    scanf(" %c", &c);
    int n = 0;
    int a[1000];

    int low = 0;
    int high;

    if(c == 'y')
    {
        printf("Enter the size of array:\n");
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        low = 0;
        high = n - 1;
        start = clock();
        quicksort(low, high, a);
        end = clock();



        printf("After sorting:  \n");
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");

            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("\n");
            printf("time taken for %d inputs = %lf seconds\n", n, cpu_time_used);
    }
    else{
         n = 50;
        while(n <= 1000)
        {

            for(int i = 0; i < n; i++)
            {
                a[i] = rand() % n;
            }

            low = 0;
            high = n - 1;
            start = clock();
            quicksort(low, high, a);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("\n");
            printf("time taken for %d inputs = %lf seconds\n", n, cpu_time_used);

            n = n + 50;
        }

    }

    // for(int j = 0; j < n; j++)
    // {
    //     printf("%d ", a[0][j]);
    // }
}

void quicksort(int low, int high, int a[])
{
    if(low < high)
    {
        delay(1);
        int pivot_pos = partition(low, high, a);
        quicksort(low, pivot_pos - 1, a);
        quicksort(pivot_pos + 1, high, a);
    }

}

int partition(int low, int high, int a[])
{
    int i = low + 1, j = high, k;

        while(a[j] > a[low])
        {
            delay(1);
            j--;
        }
        while(a[i] < a[low] && i <= high)
        {
            delay(1);
            i++;
        }
    while(i < j)
    {

         k = a[j];
         a[j] = a[i];
         a[i] = k;
         i++;
         j--;
         delay(1);
        while(a[j] > a[low])
        {
            j--;
            delay(1);
        }
        while(a[i] < a[low])
        {
            i++;
            delay(1);
        }


    }
    k = a[i - 1];
    a[i - 1] = a[low];
    a[low] = k;
    delay(1);
    return i - 1;
}

void delay(int num)
{
    int seconds = 1000 * num;

    clock_t start_time = clock();

    while (clock() < start_time + seconds);
}