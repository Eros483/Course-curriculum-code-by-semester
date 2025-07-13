#include <stdio.h>
int main()
{
    int n, j=1, product=1;
    printf ("Please input number of whose factorial is to be found:\n");
    scanf ("%d", &n);
    if (n<0)
    {
        printf ("Factorial not defined\n");
    }
    else if (n==0)
    {
        printf ("The value of the factorial is 1\n");
    }
    else
    {
        do
            {
                product=product*j;
                j++;
            }        
        while (j<=n);
        printf ("The factorial of %d is: %d\n", n, product);
    }
    return 0;      
}
