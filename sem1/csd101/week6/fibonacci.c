#include<stdio.h>

int main()
{
	int fibonacci[1000],n,i;
	fibonacci[1]=1;
	fibonacci[2]=1;
	fibonacci[3]=2;
	printf ("Number of fibonacci numbers needed:\n");
	scanf("%d", &n);
	for (i=4; i<=n; i++)
	{
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
	}
	printf ("The input array is\n");
	for(i=1; i<=n; i++)
	{
		printf ("%d\n", fibonacci[i]);
	}
	return 0;	
}
