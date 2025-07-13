import java.util.Scanner;

class SleepThread extends Thread {
    private long sleepTime;
    private String threadName;

    public SleepThread(long sleepTime, String threadName) {
        this.sleepTime = sleepTime;
        this.threadName = threadName;
    }

    @Override
    public void run() {
        try {
            System.out.println(threadName + ": Sleeping for " + sleepTime + " milliseconds.");
            Thread.sleep(sleepTime);
            System.out.println(threadName + ": Woke up after " + sleepTime + " milliseconds.");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.out.println(threadName + ": Interrupted.");
        }
    }
}

public class q4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the sleep time for the main thread (x in milliseconds): ");
        long x = scanner.nextLong();

        System.out.print("Enter the sleep time for T1 (y in milliseconds): ");
        long y = scanner.nextLong();

        System.out.print("Enter the sleep time for T2 (z in milliseconds): ");
        long z = scanner.nextLong();

        // Create threads
        SleepThread t1 = new SleepThread(y, "T1");
        SleepThread t2 = new SleepThread(z, "T2");

        // Main thread behavior
        try {
            System.out.println("Main Thread: Sleeping for " + x + " milliseconds.");
            Thread.sleep(x);
            System.out.println("Main Thread: Woke up after " + x + " milliseconds.");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.out.println("Main Thread: Interrupted.");
        }

        // Start T1 and wait for it to finish
        t1.start();
        try {
            t1.join(); // Wait for T1 to finish
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.out.println("Main Thread: Interrupted while waiting for T1.");
        }

        // Start T2 and wait for it to finish
        t2.start();
        try {
            t2.join(); // Wait for T2 to finish
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.out.println("Main Thread: Interrupted while waiting for T2.");
        }

        // Close the scanner
        scanner.close();
    }
}