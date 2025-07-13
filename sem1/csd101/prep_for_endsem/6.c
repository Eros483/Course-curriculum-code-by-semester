#include <stdio.h>
int main()
{
    int *px;
    int *py;
    int a[6]={1, 2, 3, 4, 5, 6};
    px=&a[0];
    py=&a[4];
    printf("py-px=%d", py-px);
}