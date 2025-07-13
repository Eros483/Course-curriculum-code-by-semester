import java.util.Scanner;

public class q3{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n=scanner.nextInt();

        int[] integers=new int[n];
        for (int i=0;i<n;i++){
            integers[i]=scanner.nextInt();
        }
        int k=0;
        int[] primes=new int[n];
        for (int j=0;j<n;j++){
            if (primeChecker(integers[j])){
                primes[k]=integers[j];
                k++;
            }
        }

        for (int l=0; l<k; l++){
            System.out.print(primes[l]+" ");
        }
    }

    public static boolean primeChecker(int x){
        if (x<=1){
            return false;
        }

        for (int i=2;i<x;i++){
            if (x%i==0){
                return false;
            }
        }

        return true;
    }
}