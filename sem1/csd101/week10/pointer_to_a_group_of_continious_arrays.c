#include <stdio.h>
#define MAXCOLS 60
int main()
{
    int(*a)[MAXCOLS];
    int(*b)[MAXCOLS];
    int(*c)[MAXCOLS];

    int i, j;

    *(*(c+i)+j)=*(*(a+i)+j)=*(*(b+i)+j);
}