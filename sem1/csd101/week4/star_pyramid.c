#include <stdio.h>
int main()
{
int x, stars, spaces, rows;
scanf ("%d", &rows);
for (x=1; x<=rows; x++)
{
for (spaces=rows-x; spaces>=0; spaces--)
{
printf (" ");
}
for (stars=1; stars <=((2*x)-1); stars=stars+1)
{
printf ("*");
}
printf("\n");
}
return 0;
} 
