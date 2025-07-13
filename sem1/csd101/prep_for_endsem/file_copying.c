#include <stdio.h>
//#include <conio.h>
int main()
{
    FILE*fp;
    char ch, fname[50];
    printf ("Enter i/p file name ");
    gets(fname);
    if ((fp=fopen(fname, "r"))==NULL)
        printf("Can not open file\n");
    else
    {
        fscanf(fp, "%c", &ch);
        while(!feof(fp))
        {
            printf("%c", ch);
            fscanf(fp, "%c", &ch);
        }
    }
    fclose(fp);
}