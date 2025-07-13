#include <stdio.h>
#include <string.h>
void similiar (char x[100], int i);

int main()
{
    int k;
    char str[100];
    scanf("%s", &str);
    for (k=0; k<100; k++)
    {
        similiar (str, k);
    }
    printf("%ld", strlen(str));
}

void similiar (char x[100], int i)
{
    int j;
    if (x[i]!='\0')
    {
        for (j=1; i+j<=100; j++)
        {
            if (x[i]==x[i+j])
            {
                x[i+j]='\0';
            }
        }
    }
}