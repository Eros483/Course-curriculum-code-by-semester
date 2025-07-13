#include <stdio.h>
int main()
{
    float number1, number2, product;
    int lower, upper, step;
    number1=9.7;
    lower=1.0;
    upper=10.0;
    step=1.0;
    number2=lower;
    while(number2<=upper)
    {
        product=number1*number2;
        printf ("%0.1f times %0.3f is %0.3f.\n",number1,number2,product);
        number2=number2+step;
    }
    return 0;
}