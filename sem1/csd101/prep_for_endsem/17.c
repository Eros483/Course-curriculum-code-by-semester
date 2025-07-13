#include <stdio.h>
int main()
{
    ///FILE*ptr=fopen("hello.txt", "w");
    ///char string[]="hello lol";
    ///fputs(string, ptr);

    FILE*ptr2=fopen("hello.txt", "r");
    char hi[1000];
    while (fgets(hi, 1000, ptr2)!=NULL)
    {
        printf("%s\n", hi);
    }

    FILE*ptr3=fopen("ok.txt", "w");
    fputs(hi, ptr3);
}