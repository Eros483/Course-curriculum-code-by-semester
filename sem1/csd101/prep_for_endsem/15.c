#define MAX 100
int positions_1[MAX], positions_2[MAX], positions_3[MAX];
#include <stdio.h>
#include <string.h>
int character_checker(char string[MAX], char c);
int main()
{	
	int k, l, m, n, q, z;
	char s1[MAX];
	char s2[3];
	printf("Please enter s1: \n");
	scanf("%s", s1);
	printf("Please enter s2: \n");
	scanf("%s", s2);
	character_checker(s1, s2[0]);
	for (k=0; k<MAX; k++)
	{
		if (s1[(positions_1[k])+1]==s2[1])
		{
			for (l=0; l<MAX; l++)
			{
				positions_2[l]=k;
			}
		}
	}
	for (m=0; m<=MAX; m++)
	{
		if (s1[(positions_2[m])+2]==s2[2])
		{
			for (n=0; n<MAX; n++)
			{
				positions_3[n]=positions_2[m];
			}
		}
	}
	for (q=0; q<MAX; q++)
	{
		s1[(positions_3[q])]='s';
		s1[(positions_3[q])+1]='n';
		s1[(positions_3[q])+2]='u';
	}
	for (z=0; z<MAX && s1[z]!= '\0'; z++)
    {
        printf("%c", s1[z]);
    }
}
int character_checker(char string[MAX], char c)
{	
	int i, j=0;
	for (i=0; i<MAX; i++)
	{
		if (string[i]==c)
		{
			positions_1[j]=i;
			j++;
		}
	}
}		
