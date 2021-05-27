#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mergesort(int arr[], int l, int r);
void merge(int arr[],int l, int mid, int r);

void delay(int num);

int main()
{
    int n;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("do you want random input: ");
    char c;
    scanf(" %c", &c);

    int arr[n];

    if(c == 'n')
    {
        printf("Enter the elements of the array: ");

        for(int i = 0; i < n ; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    else
    {
        printf("Random input is : ");
        for(int i = 0; i < n ; i++)
        {
            arr[i] = rand() % 1000;
            printf(" %d ", arr[i]);
        }
    }


    printf("\n");

    start = clock();
    mergesort(arr, 0, n - 1);
    end = clock();
    printf("After sorting: ");
    for(int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("time taken = %lf seconds\n", cpu_time_used);
}
void mergesort(int arr[], int l, int r)
{
    delay(10);
    if(l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr,l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void merge(int arr[],int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r- mid;

    int a[n1];
    int b[n2];

    for(int i = 0; i < n1; i++)
    {
        delay(10);
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        delay(10);
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            delay(10);
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            delay(10);
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i < n1)
    {
        delay(10);
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        delay(10);
        arr[k] = b[j];
        k++;
        j++;
    }
}
void delay(int num)
{
    int seconds = 1000 * num;

    clock_t start_time = clock();

    while (clock() < start_time + seconds);
}