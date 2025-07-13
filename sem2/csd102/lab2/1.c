#include <stdio.h>

int main()
{
    int nums[100], n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int b=1;
    while (b<=n)
    {
        int k=0;
        
        for (int x=0; x<n; x++)
        {
            if (nums[x]==b)
            {
                k=1;
                break;
            }
        }

        if (k==0)
        {
            printf("%d ", b);
        }

        ++b;
    }

    return 0;
}