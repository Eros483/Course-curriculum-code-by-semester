#include <stdio.h>
int main()
{
	int matrix1[1000][1000];
	int matrix2[1000][1000];
	int matrix3[1000][1000];
	int i, j, k, l, r1, r2, r3, c1, c2, c3;
	printf ("Please input the number of rows and columns in matrix 1 and matrix 2 respectively:\n");
	scanf ("%d%d%d%d", &i, &j, &k, &l);
	if (j!=k)
	{
		printf ("The matrices aren't compatible");
	}
	else
	{
		printf ("Please input the values of matrix1");
		for (r1=1; r1<=i; r1++)
		{
			for (c1=1; c1<=j; c1++)
			{
				printf ("matrix1[%d][%d]", r1, c1);
				scanf("%d", &matrix1[r1][c1]);
			}
		}
		printf ("Please input the values of matrix2");
		for (r2=1; r2<k; r2++)
		{
			for (c2=1; c2<=l; c2++)
			{
				printf ("matrix2[%d][%d]", r2, c2);
				scanf("%d", &matrix2[r2][c2]);
			}
		}
		for (r1=1; r1<=i; r1++)
		{
			for (c1=1; c1<=j; c1++)
			{
				for (r2=1; r2<k; r2++)
				{
					for (c2=1; c2<=l; c2++)
					{
						for (r3=1; r3<=k; r3++)
						{
							for (c3=1; c3<=j; c3++)
							{
							matrix3[r3][c3]=matrix1[r1][c3]*matrix2[r3][c2];
							}
						}
					}
				}
			}
		}
		for (r3=1; r3<=k; r3++)
		{
			for (c3=1; c3<=j; c3++)
			{
				printf ("%c", matrix3[r3][c3]);
			}
		}
		return 0;
	}
	
}
						
					 
		
	
