#include <stdio.h>
#define MAX 100
int sums[MAX];
int x=0;
int TOP;

int sum_checker (int array[MAX], int z, int n);

int max_finder (int array[MAX]);

int main()
{
    int nums[100], n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int l;
    for (l=0; l<n; l++)
    {
        sum_checker(nums, l, n);
    }
    max_finder(sums);
    printf("%d\n", TOP);
    return 0;
}

int sum_checker (int array[MAX], int z, int n)
{
    int k;
    for (k=2; k+z<n; k++)
    {
        sums[x]=array[z]+array[z+k];
        ++x;
    }
}

int max_finder (int array[MAX])
{
    TOP=array[0];
    for (int q=0; q<x; q++)
    {
        if (TOP<array[q])
        {
            TOP=array[q];
        }
    }
}