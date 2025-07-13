#include <stdio.h>
#include <stdlib.h>

int f(const void *x, const void *y);
void rotater(int a[], int b);
int comparer(int a[], int b[], int c);

int main(void) {
    int nums[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int nums2[100];
    for (int j = 0; j < n; j++) {
        nums2[j] = nums[j];
    }
    qsort(nums2, n, sizeof(int), f);
    int rotations;
    for (rotations = 0; rotations<10*n; rotations++)
    {
        if (comparer(nums, nums2, n)==1)
        {
            break;
        }
        rotater(nums, n);
    }
    printf("%d\n", rotations);

    return 0;
}

int f(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}

void rotater(int a[], int b) {
    int temp = a[0];
    for (int d = 1; d < b; d++) {
        a[d - 1] = a[d];
    }
    a[b - 1] = temp;
}

int comparer(int a[], int b[], int c) {
    for (int k = 0; k < c; k++) {
        if (b[k] != a[k]) {
            return 0;
        }
    }
    return 1;
}
