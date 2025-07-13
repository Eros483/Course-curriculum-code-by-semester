#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int i, j;
    double x, y;
    char c='c', d='d';
    float result;
    printf ("Please input integral values for i, j and any desirable value for x, y\n");
    scanf ("%d", &i);
    scanf ("%d", &j);
    scanf ("%lf", &x);
    scanf ("%lf", &y);
    result=fabs(x+y);
    printf ("The answer is %0.2f\n", result);
}