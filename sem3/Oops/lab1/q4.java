import java.util.Scanner;

public class q4 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter value for N:");
        int n=sc.nextInt();

        for (int i=1;i<n+1;i++){
            if (div3(i) && div5(i)){
                System.out.println(i+" FizzBuzz ");
                continue;
            }

            else if (div5(i)){
                System.out.println(i+" Buzz ");
                continue;
            }

            else if (div3(i)){
                System.out.println(i+" Fizz ");
                continue;
            }

            else{
                System.out.println(i+" ");
            }
        }
    }

    public static boolean div3(int n){
        if (n%3==0){
            return true;
        }
        else{
            return false;
        }
    }

    public static boolean div5(int n){
        if (n%5==0){
            return true;
        }
        else{
            return false;
        }
    }
}