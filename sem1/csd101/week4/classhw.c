#include <stdio.h>
int main()
{
    int rows, rowno, stars, spaces;
    printf ("Please input desired number of rows\n");
    scanf ("%d", &rows);
    for (rowno=1; rowno<=rows; rowno++)
    {
        for (spaces=rows-rowno; spaces>=0; spaces--)
        {
            printf (" ");
        }
        for (stars=1; stars <=(2*rowno)-1; stars++)
        {
            if (stars==rowno)
            {
                printf ("+");
            }
            else
            {
                printf ("*");
            }
        }
        printf ("\n");
    }
    return 0;
}