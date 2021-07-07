#include<stdio.h>
#include<math.h>
int n;
int x[10];
int place(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if((x[j]==i) || (abs(x[j]-i) == (abs(j-k))))
            return 0;
    }
    return 1;
}
void nqueens(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                printf("\nSOLUTION ARE\n");
                for(int i=1;i<=n;i++)
                {
                    printf("%d\t",x[i]);
                }
                printf("\n");
            }
            else
            {
                nqueens(k+1,n);
            }
        }
    }
}
int main()
{
    printf("Enter the Number of the queens\n");
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    {
        nqueens(k,n);
    }

}
