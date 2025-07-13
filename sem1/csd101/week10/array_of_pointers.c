#include <stdio.h>
#define MAXROWS 60
int main()
{
    int(*a)[MAXROWS];
    int(*b)[MAXROWS];
    int(*c)[MAXROWS];

    int i, j;
    
    *(c[i]+j)=*(a[i]+j)+*(b[i]+j);
}