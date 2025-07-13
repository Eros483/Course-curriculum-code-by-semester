//in selection sort we repeatedly swap the minimum element of the unsorted portion of the array and then swap it with the first element of the same unsorted portion, then increment the index to begin the same process from the next step

#include <stdio.h>//standard C libraries
#include <stdlib.h>

void swap(int *pa, int *pb);//swapping the min element with the index
void selection_sort(int arr[], int n);//estabilished sorting algorithm
void print(int arr[], int n);//to print array simplifying code

int main()
{
    printf("Please enter number of elements required in the array to be sorted: \n");//taking input for user defined arrray
    int x;
    scanf("%d", &x);
    int*array= (int*)malloc(sizeof(x*sizeof(int)));
    for (int i=0; i<x; i++)
    {
        printf("Enter the value of array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Unsorted array:\n");//original array
    print(array, x);
    selection_sort(array, x);
    printf("Sorted array:\n");//final array
    print(array, x);
}

void swap(int *pa, int *pb)//swapping two elements via pointer
{
    int temp;
    temp=*pa;
    *pa=*pb;
    *pb=temp;
}

void print(int arr[], int n)//printing the array
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n) 
{
    int index;//element to be checked

    for (int i = 0; i < n-1; i++)//setting up increment loops 
    {
        index = i;//reinitialising value everytime loop is initiated
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[index])//checking th
            {
                index = j;
            }
        }
        swap(&arr[index], &arr[i]);//swapping as per method
    }
}
