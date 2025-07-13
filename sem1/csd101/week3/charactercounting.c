#include <stdio.h>
#define EOL '\n'
int main()
{
    int nc;
    nc=0;
    while(getchar()!=EOL)
    {
        ++nc;
    }
    printf ("%d is the number of words in this statment\n",nc);
    return 0;
}