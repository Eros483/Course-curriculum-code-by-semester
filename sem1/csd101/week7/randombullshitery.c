#include <stdio.h>
int sum=0;
int lines=0;
int linecount (void);
int main()
{
int n;
float avg;
printf("Enter the text below\n");
while ((n=linecount())>0){
sum+=n;
++lines;
}
avg= (float) sum/lines;
printf("Average number of characters per line: %5.2f", avg);
}
int linecount(void)
{
char line[80];
int count=0;
while ((line[count]=getchar())!='\n')
++count;
return (count);
}