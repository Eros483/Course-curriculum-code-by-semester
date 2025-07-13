import java.util.Scanner;

public class q8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] array = new int[10];
        System.out.println("Enter 10 integers:");
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        // Sort the array using insertion sort
        insertionSort(array);

        System.out.println("Sorted array:");
        printArray(array);

        System.out.println("Enter the element to search:");
        int target = scanner.nextInt();

        // Perform binary search
        int result = binarySearch(array, target);

        if (result == -1) {
            System.out.println("Element not found.");
        } else {
            System.out.println("Element found at index: " + result);
        }

        scanner.close();
    }

    public static void insertionSort(int[] integers) {
        int n = integers.length;
        for (int i = 1; i < n; i++) {
            int key = integers[i];
            int j = i - 1;
            while (j >= 0 && integers[j] > key) {
                integers[j + 1] = integers[j];
                j--;
            }
            integers[j + 1] = key;
        }
    }

    public static int binarySearch(int[] sortedArray, int target) {
        int left = 0;
        int right = sortedArray.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (sortedArray[mid] == target) {
                return mid;
            }

            if (sortedArray[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
