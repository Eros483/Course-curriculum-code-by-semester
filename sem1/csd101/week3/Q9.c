#include <stdio.h>
#include <math.h>
int main ()
{
float x, xavg, product=1.0;
int n=0;
while (n!=10)
{
printf ("please enter values of x\n");
scanf ("%f", &x);
product=product*x;
++n;
}
xavg= pow(product,(1.0/n));
printf ("the geometric mean is %f\n",xavg);
return 0;
}

