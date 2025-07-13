#include <stdio.h>
void foo(float f[]);
int main()
{
    float array[5]={10, 20, 30, 40, 50};
    foo(&array[2]);
}
void foo(float f[])
{
    printf("%f\n", *f);
    printf("%p\n",f);
    float x;
    x=*f+2;
    *f=(*f)+2;
    printf("%f\n", *f);
    printf("%f\n", x);
    printf("%p\n", f);
    printf("%p\n", &x);
}