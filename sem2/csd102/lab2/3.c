#include <stdio.h>

int bs(int a[], int i, int j, int x);

int main(void) {
    int nums[100], n, target;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);
    bs(nums, 0, n - 1, target);
    return 0;
}

int bs(int a[], int i, int j, int x) {
    int mid;
    if (i == j) {
        if (a[i] == x) {
            printf("%d", i);
        } else {
            printf("-1");
        }
    } else {
        mid = (i + j) / 2;
        if (a[mid] == x) {
            printf("%d", mid);
        } else {
            if (a[mid] > x) {
                bs(a, i, mid - 1, x);
            } else {
                bs(a, mid + 1, j, x);
            }
        }
    }
    return 0;  // Include a return statement here
}
