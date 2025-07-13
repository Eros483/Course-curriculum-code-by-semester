#include <stdio.h>
int main()
{
    int a=20, b;
    b= a++ - ++a;
    printf ("%d",b);
    return 0;
}