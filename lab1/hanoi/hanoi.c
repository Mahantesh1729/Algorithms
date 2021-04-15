#include <stdio.h>

void tower(char a, char b, char c, int n);

int main()
{
    char start = 'A';
    char aux = 'B';
    char end = 'C';
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower(start, aux, end, n);
    return 0;
}

void tower(char a, char b, char c, int n)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", a, c);
        return;
    }
    tower(a, c, b, n - 1);
    printf("Move disk %d from %c to %c\n", n, a, c);
    tower(b, a, c, n - 1);
    return;
}