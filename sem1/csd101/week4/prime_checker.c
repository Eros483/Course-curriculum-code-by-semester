#include <stdio.h>
int main()
{
    int integer, divisor, remainder=1;
    printf ("Please enter integer to be checked:\n");
    scanf ("%d", &integer);
    for (divisor=2; divisor<integer; divisor++)
    {
        if (integer%divisor==0)
        {
            remainder=0;
        }
        else
        {
            ;
        }
    }
    if (remainder==1)
    {
        printf ("The chosen integer is a prime");
    }
    else
    {
        printf ("The chosen integer is not a prime");
    }
    return 0;
}