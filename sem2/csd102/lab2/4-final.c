#include <stdio.h>

int bs(int a[], int i, int j, int x);//estabilishing binary search function
int main(void)
{
    
    int nums[100], n, target;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
	}
	scanf("%d", &target);
    
    bs(nums, 0, n-1, target);
    return 0;
}	

int bs(int a[], int i, int j, int x)
{
    int mid;
    if (i==j)//aka only one element
    {
        if (a[i]==x)
        {
            printf("%d", i);//element found
        }
        else
        {
            printf("-1");//element not found
        }
    }
    else
    {
        mid=(i+j)/2;//declaring point of splitting arrray
        if (a[mid]==x)
        {
            printf("%d", mid);//aka if middle element is desired element
        }
        else
        {
            if (a[mid]>x)
            {
                bs(a, i, mid-1, x);//calling recursive for 1st half of array
            }
            else
            {
                bs(a, mid+1, j, x);//for 2nd half
            }
        }
    }
    return 0;
}