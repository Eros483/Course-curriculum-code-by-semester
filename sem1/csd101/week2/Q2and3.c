#include <stdio.h>
int main()
{
float fahrenheit, celsius;
int lower, upper, step;
lower=0;
upper=60;
step=20;
fahrenheit=lower;
printf("the conversion between celsius and fahrenheit is as follows\n");
while (fahrenheit<=upper)
{
celsius=(5.0/9.0)*(fahrenheit-32);
printf("%2.2f ----> %2.0f\n",celsius, fahrenheit);
fahrenheit=fahrenheit +step;
}
}

