#include <stdio.h>
#define EOL '\n'
int main ()
{
    int c, n1;
    n1=0;
    while  ((c=getchar())!=EOF)
    {
        if (c==EOL)
        ++n1;
    }
    printf ("%d\n", n1);
}