#include <stdio.h>
int factorial(int j);
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("\nfactorial of %d is: %d\n", n, factorial(n));
}
int factorial(int j)
{
    int k=1;
    int i;
    if (j>1)
    {
        for (i=1; i<=j; i++)
        {
            k=k*i;
        }
    }
    return k;
}