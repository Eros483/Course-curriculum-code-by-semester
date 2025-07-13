import java.util.Scanner;

public class Queue {
    public static void main(String[] args) {
        MyQueue myQueue = new MyQueue();

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements in the queue: ");
        int n = sc.nextInt();

        myQueue.initialise(n);
        enterOption(myQueue);
    }

    public static void enterOption(MyQueue myQueue) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to display\nEnter 4 to exit\n");
        int option = sc.nextInt();
        options(option, myQueue);
    }

    public static void options(int x, MyQueue myQueue) {
        Scanner scan = new Scanner(System.in);
        switch (x) {
            case 1:
                // for insertions
                System.out.print("Enter the element to be inserted: ");
                int n = scan.nextInt();
                myQueue.enQueue(n);
                enterOption(myQueue);
                break;
            case 2:
                // for dequeueing
                myQueue.deQueue();
                enterOption(myQueue);
                break;
            case 3:
                myQueue.display();
                enterOption(myQueue);
                break;
            case 4:
                // exit
                System.out.println("System exit");
                break;
            default:
                System.out.println("Invalid option. Try again.");
                enterOption(myQueue);
                break;
        }
    }
}

class MyQueue {
    int[] queue;
    int front;
    int rear;
    int space;
    int count;

    void initialise(int n) {
        queue = new int[n];
        space = n;
        front = 0;
        rear = 0;
        count = 0;
    }

    void enQueue(int x) {
        if (count == space) {
            System.out.println("Queue is full");
        } else {
            queue[rear] = x;
            rear = (rear + 1) % space;
            count++;
        }
    }

    void deQueue() {
        if (count == 0) {
            System.out.println("Queue is empty");
        } else {
            System.out.println("Element removed: " + queue[front]);
            front = (front + 1) % space;
            count--;
        }
    }

    void display() {
        if (count == 0) {
            System.out.println("Queue is empty");
        } else {
            System.out.print("Queue elements: ");
            for (int i = 0; i < count; i++) {
                System.out.print(queue[(front + i) % space] + " ");
            }
            System.out.println();
        }
    }
}
