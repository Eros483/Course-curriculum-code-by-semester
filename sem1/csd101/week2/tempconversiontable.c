#include <stdio.h>
int main ()
{
    float fahrenheit, celsius;
    float lower, upper, step;
    lower=0.0;
    upper=60.0;
    step=20.0;
    fahrenheit=lower;
    while (fahrenheit<=upper)
    {
        celsius=(5.0/9.0)*(fahrenheit-32.0);
        printf ("The temperature in celsius and fahrenheit is %0.1f and %0.1f respectively. \n", celsius, fahrenheit);
        fahrenheit=fahrenheit+step;
    }
    return 0;
}