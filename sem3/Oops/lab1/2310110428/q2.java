import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n=scanner.nextInt();

        int[] integers=new int[n];
        for (int i=0;i<n;i++){
            integers[i]=scanner.nextInt();
        }

        int max=integers[0];
        for (int i=1; i<n; i++){
            if (integers[i]>max){
                max=integers[i];
            }
        }

        System.out.print(max);
    }
}