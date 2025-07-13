#include <stdio.h>
int f(int x, int y)
{
    if (y==0)
        return x;
    else
        return f(x^y, (x&y)<<1);
}
int main()
{
    int ok=f(12,15);
    printf("%d", ok);
}
