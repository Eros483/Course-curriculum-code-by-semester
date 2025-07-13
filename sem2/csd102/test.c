
#include <stdio.h>

int main() {
   int a[2][3][2] = {2,4,7,8,3,4,2,2,2,3,3,4};
printf("%u %u %u %d \n", a, *a, **a, ***a);
printf("%u %u %u %d", a+1, *a+1, **a+1, ***a+1);

    return 0;
}