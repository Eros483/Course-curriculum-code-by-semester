import java.util.Scanner;

public class q7{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] array = new int[10];
        for (int i=0;i<10;i++) {
            array[i] = scanner.nextInt();
        }
        insertionSort(array);

        System.out.println("post sorting");
        for (int l=0; l<10; l++){
            System.out.print(array[l]+" ");
        }
    }

    public static void insertionSort(int[] integers) {
        int n = integers.length;

        for (int i = 1; i < n; i++) {
            int a = integers[i];
            int j = i - 1;

            while (j >= 0 && integers[j] > a) {
                integers[j + 1] = integers[j];
                j--;
            }

            integers[j + 1] = a;
        }
    }
}
