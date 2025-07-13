#include<stdio.h>
int main()
{
    int n;
    printf("Please enter how many fibionacci numbers needed:");
    scanf("%d", &n);
    fibonacci_founder(n);
}
/*int fibonacci_founder(int n)
{
    static int pair1_fib;
    static int pair2_fib;
    int fib1=0, fib2=1, fib3=1, i;
    if (n==1)
        printf("%d\n", fib1);
    else if (n==2)
        printf("%d\n%d\n", fib1, fib2) ;
    else if (n>=3)
        printf("%d\n%d\n%d\n", fib1, fib2, fib3);
    else if (n>=4)
        printf("%d\n%d\n%d\n", fib1, fib2, fib3);
        int sum=fib2+fib3;//sum=2
        pair1_fib=fib3;//1
        pair2_fib=sum;//2
        printf("%d\n", pair2_fib);//2 
        for (i=5; i<=n; i++)
        {
            sum=pair1_fib+pair2_fib;//1+2
            pair1_fib=pair2_fib;//3
            pair2_fib=sum;//5
            //printf("%d", pair1_fib);
            printf("%d\n", pair2_fib);//5, 
        }
    else
        print("invaluid\n");
}*/