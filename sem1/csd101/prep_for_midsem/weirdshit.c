#include <stdio.h>
long int factorial(int n)
{
    if (n==0)
        return 1;
    else
        return (n*(factorial(n-1)));
}
int main()
{
    int n;
    printf ("Please enter the number:\n");
    scanf ("%d", &n);
    printf ("%d", factorial(n));
}