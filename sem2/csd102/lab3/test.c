#include <stdio.h>
int main()
{
    int n1;
    scanf("%d", &n1);
    int array[n1];
    for (int x=0; x<n1; x++)
    {
        scanf("%d", &array[x]);
    }

    for (int z=0; z<n1; z++)
    {
        printf("%d", array[z]);
    }
}