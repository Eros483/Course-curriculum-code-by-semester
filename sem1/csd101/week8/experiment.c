#include <stdio.h>
int main()
{
    int x, *px;
    px=&x;
    x=0;
    printf("x=%d\n", x);
    printf("px=%p\n", px);
    printf("*px=%d\n", *px);
}