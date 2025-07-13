#include <stdio.h>
int main()
{
    int rows, stars, spaces, rowno;
    printf ("Please input number of rows needed:\n");
    scanf ("%d", &rows);
    for (rowno=1; rowno<=rows; rowno++)
    {
        for (spaces=rows-rowno; spaces>=0; spaces--)
        {
            printf (" ");
        }
        for (stars=1; stars<=(2*rowno)-1; stars++)
        {
            printf ("*");
        }
        printf ("\n");
    }
}