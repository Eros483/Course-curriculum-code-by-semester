#include <stdio.h>
int linecount(void);
int main()
{
    int chars_per_line;
    int no_of_lines;
    int total_no_of_chars;
    int average;

    printf("Enter the text below: \n");

    while((chars_per_line=linecount()>0))
    {
        total_no_of_chars+=chars_per_line;
        ++no_of_lines;
    }
    average=(float)total_no_of_chars/no_of_lines;
    printf("\nAverage number of characters per line are : %5.2f", average);
}

int linecount(void)
{
    char line[80];
    int no_of_lines=0;
    while(((line[no_of_lines]=getchar())!='\n'))
    {
        ++no_of_lines;
    }
    return no_of_lines;
}