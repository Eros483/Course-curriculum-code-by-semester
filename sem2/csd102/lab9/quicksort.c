#include <stdio.h>//requisite libraries
#include <stdlib.h>

void swap(int *a, int *b);//functions to enable quicksort functioning
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void print(int arr[], int size);

int main() 
{
    int n;
    printf("How many elements are to be sorted?: ");
    scanf("%d", &n);
    int*array=(int*)malloc(n*sizeof(int));
    printf("Please enter needed elements:\n");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &array[i]);
    }//user selected array
    printf("Original array: \n");
    print(array, n);

    quickSort(array, 0, n - 1);
    printf("Sorted array: \n");
    print(array, n);
    return 0;

    free(array);//clearing up memory allocation
}

