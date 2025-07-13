#include <stdio.h>
#define LOWER 0
#define UPPER 60
#define STEP 20
int main ()
{
    int fahrenheit;
    printf ("The conversion table from fahrenheit to celsius is as follows \n");
    for (fahrenheit=LOWER; fahrenheit<=UPPER; fahrenheit=fahrenheit+STEP)
    {
        printf ("%2d --- %3.2f \n", fahrenheit, (5.0/9.0)*(fahrenheit-32));
    }
    return 0;
}
