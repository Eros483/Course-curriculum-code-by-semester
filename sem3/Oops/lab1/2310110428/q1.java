import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.print("Enter number: ");
        int num=scanner.nextInt();

        int factorial;
        if (num==1) {
            factorial=1;
        }

        else {
            factorial=1;
            while (num!=0){
                factorial=factorial*(num);
                num=num-1;
            }
        }

        System.out.println(factorial);
    }
}