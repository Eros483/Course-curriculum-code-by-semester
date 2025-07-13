//this feature is called method overloading. it allows us to call multiple functions with different input parameters usually to achieve the same task. for example here the same sorting method is being carried out but with different kind of inputs to achieve different types of sorting.

import java.util.Scanner;

public class q5 {

    public void sort(int[] arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public void sort(int[] arr, int n, boolean reverse) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (reverse ? arr[j] < arr[j + 1] : arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public void sort(String[] arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    String temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public void printArray(String[] arr) {
        for (String s : arr) {
            System.out.println(s);
        }
    }

    public void printArray(int[] arr) {
        for (int i : arr) {
            System.out.println(i);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        q5 sorter = new q5();

        System.out.println("Enter the size of the integer array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        sorter.sort(arr, n);
        System.out.println("Ascending order:");
        sorter.printArray(arr);

        sorter.sort(arr, n, true);
        System.out.println("Descending order:");
        sorter.printArray(arr);

        System.out.println("Enter the size of the string array: ");
        int m = sc.nextInt();
        sc.nextLine();

        String[] strArr = new String[m];
        System.out.println("Enter elements: ");
        for (int i = 0; i < m; i++) {
            strArr[i] = sc.nextLine();
        }

        sorter.sort(strArr, m);
        System.out.println("Sorted:");
        sorter.printArray(strArr);
    }
}
