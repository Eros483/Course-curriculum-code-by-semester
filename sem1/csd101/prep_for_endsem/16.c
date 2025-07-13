#include <stdio.h>
int sum=0, x, y;
#define MAX 100
int factor(int n);
int recursive (int i);
int main()
{
	int range[MAX];
	printf("Please enter lower and upper limit of the range: \n");
	scanf("%d", &x);
	scanf("%d", &y);
    if (factor(x))
    {
        recursive(x+1);
    }
    else
    {
        recursive(x);
    }
    printf("%d", sum);
}
int recursive (int i)
{
    if (i<y)
    {
        if (factor(i))
        {
            sum+=i;
        }
        i++;
        recursive(i);
    }
}
int factor(int n)
{
	if ((n%3)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}	 
		