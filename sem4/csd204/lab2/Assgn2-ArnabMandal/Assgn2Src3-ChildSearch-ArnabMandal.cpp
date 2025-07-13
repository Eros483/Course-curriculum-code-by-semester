#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int childSearch(int a[], int n, int target) {
    int left=0, right=n-1;
    while (left<=right) {
        int mid=left+(right-left)/2;
        if (a[mid]==target)
            return mid;
        else if (a[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1; // Target not found, search failure
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Execution failed: Insufficient arguments" << endl;
        return -1;
    }

    // Convert string array to integer array
    char* arrString = argv[1];
    int target = atoi(argv[2]);

    int arr[50]; //giving sufficient space
    int n = 0;
    char* token = strtok(arrString, " ");
    while (token != NULL) {
        arr[n++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int binary_search_result = childSearch(arr, n, target);

    if (binary_search_result != -1) {
        cout << "Target found at index " << binary_search_result << endl;
    } else {
        cout << "Target not found in array" << endl;
    }

    return 0;
}
