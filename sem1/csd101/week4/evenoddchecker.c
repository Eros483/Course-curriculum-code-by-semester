#include <stdio.h>
int main()
{
    int number;
    printf ("Please enter any number:\n");
    scanf ("%d", &number);
    if (number%2==0)
    {
        printf ("The chosen number is an even number\n");
    }
    else
    {
        printf ("The chosen number is an odd number\n");
    }
return 0;
}