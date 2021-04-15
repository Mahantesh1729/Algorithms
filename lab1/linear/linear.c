#include <stdio.h>
#include <stdbool.h>

#define N 100

int a[N];

bool search(int k, int n);

int main()
{
    printf("HOW many elements do you want to enter in the array: \n");
    int n;
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");

    int k;

    scanf("%d", &k);

    if(search(k , n - 1))
    {
        return 0;
    }
    printf("Element not found\n");
    return 1;

}

bool search(int k, int n)
{
    if(n == 0)
    {
        if(a[0] == k)
        {
            printf("Found\n");
            return true;
        }
        return false;
    }
    if(search(k, n - 1))
    {
        return true;
    }
    if(a[n] == k)
    {
        printf("Found\n");
        return true;
    }
    return false;
}