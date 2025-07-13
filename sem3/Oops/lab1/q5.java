import java.util.Scanner;
import java.lang.Math;

public class q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter monthly interest rate: ");
        double rate = sc.nextDouble();

        System.out.println("Enter number of years: ");
        double years = sc.nextDouble();

        System.out.println("Enter loan amount: ");
        double loanAmount = sc.nextDouble();

        double monthlyAmount;

        double x=Math.pow((1.0+rate),(years*12.0));

        monthlyAmount=(loanAmount*rate)/(1.0-(1.0/x));

        System.out.printf("monthly loan amount: %.2f", monthlyAmount);
    }
}