#include <stdio.h>
#include <stdlib.h>

void function(int arr[], int n);//to sort function 
void print(int arr[], int n);//to print function 

int main() 
{
    printf("Enter number of elements required in array\n");
    int n;
    scanf("%d", &n);
    printf("Enter values of each element\n");
    int*arr=(int*)malloc(n*sizeof(int));//setting up memory allocation
    for (int j=0; j<n; j++)
    {
        scanf("%d", &arr[j]);
    }//sorting user inputted array
    printf("Originally\n");
    print(arr, n);//original array

    function(arr, n);//sorting array

    printf("Sorted\n");
    print(arr, n);//sorted array
    free(arr);
    return 0;
}

void function(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];//element being checked
        j = i - 1;//element before checked element
        //logic is to test each element before the element that is to be checked that if it is greater or lesser than the element that is being checked. Accordingly elements are shifted.
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;//shifting accordingly
        }
        arr[j + 1] = key;//increment
    }
}

void print(int arr[], int n)//to simplify main function 
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


