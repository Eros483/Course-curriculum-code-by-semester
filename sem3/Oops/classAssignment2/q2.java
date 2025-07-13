import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        int[] arr = new int[11];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.length; i++) {
            System.out.println("Enter number: ");
            arr[i] = sc.nextInt();
        }
        System.out.println("Original Array: ");
        arrayDisplay(arr);

        for (int j = 0; j <= 5; j++) {
            int temp=arr[arr.length-j-1];
            arr[arr.length-j-1]=arr[j];
            arr[j]=temp;
        }

        System.out.println("\nReversed Array: ");
        arrayDisplay(arr);
    }

    public static void arrayDisplay(int[] arr){
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}