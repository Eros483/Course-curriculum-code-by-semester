//divide and conquer form of sorting

#include <stdio.h>
#include <stdlib.h>

void merger(int arr[], int left, int middle, int right);
void merge_sort(int arr[], int left, int right);

int main() 
{
    int size;
    printf("How many elements are to be sorted?: ");
    scanf("%d", &size);
    int*arr=(int*)malloc(size*sizeof(int));
    printf("Please enter needed elements:\n");
    for (int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }//user selected array

    merge_sort(arr, 0, size - 1);

    printf("Sorted array is \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void merger(int arr[], int left, int middle, int right) 
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //temp arrays
    int L[n1], R[n2];

    //shifting
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {    
        R[j] = arr[middle + 1 + j];
    }
    //remerge
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //assuming L is bigger
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //assuming R is bigger
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int middle = left + (right - left) / 2;

        // Sort first and second halves recursively
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merger(arr, left, middle, right);
    }
}

