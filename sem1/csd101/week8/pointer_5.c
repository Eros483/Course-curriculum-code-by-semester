#include <stdio.h>
void process(float z[]);
int main()
{
    float z[100];
    process (&z[50]);
}
void process (float f[])
{
    ;
}
