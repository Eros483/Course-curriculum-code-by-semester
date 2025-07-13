import java.util.Scanner;

public class q9 {
    public static void main(String[] args) {
        bankAccount Person= new bankAccount();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Account Holder Name: ");
        String name = sc.nextLine();

        System.out.println("Enter Account Number: ");
        int number = sc.nextInt();

        System.out.println("Enter Account Type: ");
        String type = sc.next();

        System.out.println("Enter Account Balance: ");
        double balance = sc.nextDouble();

        Person.details(name, number, type, balance);

        System.out.println("Enter amount to be deposited: ");
        double amount = sc.nextDouble();

        Person.deposit(amount);

        Person.withdraw();
        Person.display();
    }
}

class bankAccount{

    String Name;
    int AccountNo;
    String AccountType;
    double Balance;

    void details(String x, int y, String z, double p){
        Name=x;
        AccountNo=y;
        AccountType=z;
        Balance=p;
    }

    Scanner sc = new Scanner(System.in);

    void deposit(double x){
        Balance=Balance+x;
    }

    void withdraw(){
        System.out.println("Current Balance is: "+Balance + "\nHow much would you like to withdraw? ");
        double w = sc.nextDouble();

        if (Balance>w) {
            Balance = Balance - w;
        }

        else{
            System.out.println("Insufficient Balance");
        }
    }

    void display(){
        System.out.println("Name: "+Name+"\nBalance: "+Balance);
    }
}