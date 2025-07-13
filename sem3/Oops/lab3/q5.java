import java.util.Scanner;

public class q5 {
    public static void main(String[] args) {
        boolean[] seats = new boolean[10];

        for (int i = 0; i < seats.length; i++) {
            seats[i] = false;
        }

        for (int j = 0; j < seats.length; j++) {
            int choice = prompt();  // Save the prompt result

            if (choice == 1) {
                // First class seats
                if (isFirstClassFull(seats)) {
                    System.out.println("First class is full, is a seat in Economy acceptable? (Reply in yes/no): ");
                    Scanner sc = new Scanner(System.in);
                    String answer = sc.nextLine();

                    if (isEconomyFull(seats)) {
                        System.out.println("Economy class is full as well, next flight leaves in 3 hours.");
                    } else if (answer.equalsIgnoreCase("yes")) {
                        economyClassSeatAssignment(seats);
                    } else {
                        System.out.println("Next flight leaves in 3 hours.\n\n");
                    }
                } else {
                    firstClassSeatAssignment(seats);
                }
            } else if (choice == 2) {
                // Economy class seats
                if (isEconomyFull(seats)) {
                    System.out.println("Economy class is full, is a seat in First Class acceptable? (Reply in yes/no): ");
                    Scanner sc = new Scanner(System.in);
                    String answer = sc.nextLine();

                    if (isFirstClassFull(seats)) {
                        System.out.println("First class is full as well, next flight leaves in 3 hours.");
                    } else if (answer.equalsIgnoreCase("yes")) {
                        firstClassSeatAssignment(seats);
                    } else {
                        System.out.println("Next flight leaves in 3 hours.\n\n");
                    }
                } else {
                    economyClassSeatAssignment(seats);
                }
            }
        }

        if (isFirstClassFull(seats) && isEconomyFull(seats)) {
            System.out.println("All tickets booked, next flight leaves in 3 hours. \n\n");
        }
    }

    public static int prompt() {
        System.out.println("Please type 1 for a first class ticket or 2 for an economy class ticket: ");
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    public static boolean[] firstClassSeatAssignment(boolean[] seats) {
        for (int k = 0; k < 5; k++) {
            if (!seats[k]) {
                seats[k] = true;
                System.out.println("Assigned seat: " + (k + 1) + " in First Class.\n\n");
                break;
            }
        }
        return seats;
    }

    public static boolean[] economyClassSeatAssignment(boolean[] seats) {
        for (int k = 5; k < 10; k++) {
            if (!seats[k]) {
                seats[k] = true;
                System.out.println("Assigned seat: " + (k + 1) + " in Economy Class.\n\n");
                break;
            }
        }
        return seats;
    }

    public static boolean isFirstClassFull(boolean[] seats) {
        for (int i = 0; i < 5; i++) {
            if (!seats[i]) {
                return false;
            }
        }
        return true;
    }

    public static boolean isEconomyFull(boolean[] seats) {
        for (int i = 5; i < 10; i++) {
            if (!seats[i]) {
                return false;
            }
        }
        return true;
    }
}
