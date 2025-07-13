#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int updown(int a[], int b[], int c);

int main()
{
    int price[100], n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &price[i]);
    }
    qsort(price, n, sizeof(int), compare); 
    if (n%2!=0)
    {
        for (int l=((n+1)/2)-1; l<n; l++)
        {
            price[l]=price[l+1];
        }
        n=n-1;
    }
    int final[n];
    updown (price, final, n);
    int profit=0;
    for (int q=0; q<n; q=q+2)
    {
        profit=profit+final[q+1]-final[q];
    }
    printf("%d", profit);
}

int compare(const void *a, const void *b)
{
    return (*(int*)a-*(int*)b);
}

int updown(int a[], int b[], int c)
{
    for (int x=0; x<c/2; x++)
    {
        b[2*x]=a[x];
        b[(2*x)+1]=a[c-x-1];
    }
}