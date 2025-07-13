#include <stdio.h>
int main()
{
    float number1, number2, product;
    int lower, step, upper;
    number1=99.26;
    lower=1;
    upper=10;
    step=1;
    number2=lower;
    printf ("the multiplication table of 99.26 is as follows\n");
    while (number2<=upper)
    {
        product=number1*number2;
        printf ("%0.2f * %0.0f = %0.2f\n",number1, number2, product);
        number2=number2+step;
    }
    return 0;
}
    
