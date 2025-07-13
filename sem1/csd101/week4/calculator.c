#include <stdio.h>
int main()
{
    int x, y, product, sum, quotient, difference;
    printf ("Please enter desired value of x and y\n");
    scanf ("%d %d", &x, &y);
    char operator;
    product=x*y;
    sum=x+y;
    quotient=x/y;
    difference=x-y;
    printf ("Please select operation to be done\n");
    scanf ("%c", &operator);
    switch (operator=getchar())
    {
        case '*':
        {
            printf ("The product is %d\n", product);
            break;
        }
        case '+':
        {
            printf ("The sum is %d\n", sum);
            break;
        }
        case '/':
        {
            printf ("The quotient is %d\n", quotient);
            break;
        }
        case '-':
        {
            printf ("The difference is %d\n", difference);
            break;
        }
    }
    return 0;
}