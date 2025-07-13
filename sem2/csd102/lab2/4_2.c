#include <stdio.h>

int find_rotation_count(int arr[], int low, int high) {
    while (low <= high) {
        // If the array is already sorted, return the first index
        if (arr[low] <= arr[high]) {
            return low;
        }

        int mid = (low + high) / 2;
        int next = (mid + 1) % (high + 1); // To handle circular array

        // Check if mid is the minimum element
        if (arr[mid] <= arr[next] && arr[mid] <= arr[(mid - 1 + (high + 1)) % (high + 1)]) {
            return mid;
        }

        // Decide whether to go left or right
        if (arr[mid] <= arr[high]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // Invalid input
}

int main() {
    int arr[] = {3, 5, 6, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int rotation_count = find_rotation_count(arr, 0, n - 1);

    if (rotation_count != -1) {
        printf("The array is rotated %d times.\n", rotation_count);
    } else {
        printf("Invalid input or array is not rotated.\n");
    }

    return 0;
}