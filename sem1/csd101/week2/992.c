#include <stdio.h>
int main ()
{
    float number1,number2, product;
    float step, minimum, maximum;
    number1=992.67;
    step=1.0;
    minimum=1.0;
    maximum=10.0;
    printf ("the table of 992.67 is\n");
    number2=minimum;
    while (number2<=maximum)
    {
        product=number1*number2;
        printf ("%2.f * %0.0f = %2.2f\n",number1,number2,product);
        number2=number2+step;
    }
    return 0;
}