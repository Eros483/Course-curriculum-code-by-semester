#include <stdio.h>

int main() {
    int rows;
    
    printf("Please input the number of rows needed:\n");
    scanf("%d", &rows);
    
    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (int j = i; j <= 2 * i - 1; j++) {
            printf("%d", j);
        }
        for (int j = 2 * i - 2; j >= i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    return 0;
}
