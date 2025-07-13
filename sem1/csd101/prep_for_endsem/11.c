#include <stdio.h>
int swapper(int*px, int*py);
int main()
{
    int a, b;
    a=2;
    b=3;
    printf("a is %d and b is %d\n", a, b);
    int*pa;
    int*pb;
    pa=&a;
    pb=&b;

    swapper(pa,pb);
    printf("a is %d and b is %d\n", a, b);
}
int swapper(int*px, int*py)
{
    int temp;
    temp=*px;
    *px=*py;
    *py=temp;
}