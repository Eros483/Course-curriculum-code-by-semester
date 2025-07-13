#include <stdio.h>
int main()
{
    int M;
    int N;
    int max;
    scanf("%d", &N);
    for (M=0; M*M<N; M++)
    {
        max=M;
    }

    printf("%d\n", max);
}