#include <stdio.h>
#define F1 1
int main()
{
int F2, fn, sum, n, t2, repititions=1;
F2=F1;
printf ("Please enter number of fibonacci numbers needed\n");
scanf ("%d", &n);
printf ("the output is as follows \n");
printf ("%d\n", F1); 
printf ("%d\n", F2);
sum=F1+F2;
printf ("%d\n", sum);
fn=sum;
sum=sum+F2;
printf ("%d\n", sum);
while (repititions<=(n-4))
{
t2=fn;
fn=sum;
sum=t2+fn;
printf("%d\n", sum);
++repititions;
}
return 0;
}



