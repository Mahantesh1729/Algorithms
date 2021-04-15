#include <stdio.h>
#include <stdbool.h>
#define N 100

bool search(int k, int start, int mid, int end, int  a[],int n);

int main()
{
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements of the array: ");

    int a[N];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    printf("Enter the key element to be found: \n");

    int k;

    scanf("%d", &k);

    if(search(k, start, mid, end, a, n))
    {
        printf("Element found\n");
        return 0;
    }
    printf("Element Not found\n");
    return 1;
}

bool search(int k, int start, int mid, int end, int a[], int n)
{
    if(a[mid] == k)
    {
        return true;
    }
    else if(k < a[mid])
    {
        end = mid - 1;
        mid = (start + mid) / 2;
        if(search(k, start, mid, end, a, n))
        {
            return true;
        }
    }
    else
    {
        start = mid + 1;
        mid = (start + end) / 2;
        if(end < start)
        {
            return false;
        }
        if(search(k, start, mid, end, a, n))
        {
            return true;
        }
    }
    return false;
}