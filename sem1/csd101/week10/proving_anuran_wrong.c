#include <stdio.h>
int main()
{
    int i[10][20];
    i[5][0]=4;
    i[5][4]=5;
    int*x=*(*(i+5));
    int*y=*(*(i+5)+4);
    printf("adress of x: %p and value of x: %d", x, *x);
    printf("adress of y: %p and value of y: %d, y, *y");
}