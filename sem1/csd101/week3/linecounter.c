#include <stdio.h>
#define EOL '\n'
int main()
{
    int c, n1;
    n1=0;
    while ((c=getchar())!=EOF)
    {
        if (c==EOL)
        {
            ++n1;
        }
    }
    printf ("The number of lines in this statement is %d \n",n1);
    return 0;
}
