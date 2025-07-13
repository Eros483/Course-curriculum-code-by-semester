#include <stdio.h>

void swapper(int *pa, int *pb);

int main() {
    int x, y;
    printf("Please enter the value of x and y:\n");
    scanf("%d %d", &x, &y);
   
    int *px = &x;
    int *py = &y;
   
    printf("Original value for x is %d, and y is %d\n", x, y);
   
    swapper(px, py);
   
    printf("New value for x is %d, and y is %d\n", x, y);
   
    return 0;
}

void swapper(int *pa, int *pb) {
    int temp = *pb;
    *pb = *pa;
    *pa = temp;
}
