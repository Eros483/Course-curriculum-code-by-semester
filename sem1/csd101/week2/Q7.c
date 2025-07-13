#include <math.h>
#include <stdio.h>
int main ()
{
int a=1, b=-7, c=10;
float discriminant, root1, root2;
discriminant=b*b-4*a*c;
root1=(-b+ sqrt(discriminant))/2*a;
root2=(-b- sqrt(discriminant))/2*a;
printf ("The roots of the given equation are %2.2f and %2.2f\n", root1, root2);
return 0;
}



