class Task extends Thread {
    private String name;

    public Task(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        System.out.println(name + " started.");
        try {
            Thread.sleep(1000);  // Simulate some work with sleep
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(name + " completed.");
    }
}

public class threadJoinLearner {
    public static void main(String[] args) {
        Task task1 = new Task("Task 1");
        Task task2 = new Task("Task 2");

        task1.start();
        task2.start();

        // Without join
        System.out.println("Without join: Main thread finished without waiting for tasks.");

        // Uncomment below to see the effect of join()
        try {
            task1.join();
            task2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("With join: Main thread waited for tasks to complete.");
    }
}
