#include <stdio.h>
int main()
{
float x, F, sum, summax, product, xavg;
summax=1.0;
xavg=0;
sum=0;
while(sum!=summax)
{
printf ("Please input value of x\n");
scanf("%f\n",&x);
printf ("Please input value of F\n");
scanf("%f\n",&F);
product=F*x;
sum=sum+F;
xavg=xavg+product;
}
printf ("The value of xavg from the given inputs is %f\n",xavg);
return 0;
}

