import java.util.Scanner;

class MinimumStack {
    char stack[] = new char[10];
    int top;

    MinimumStack() {
        top = -1;
    }

    void push(char item) {
        if (top == 9)
            System.out.println("Stack is full");
        else
            stack[++top] = item;
    }

    void pop() {
        if (top < 0) {
            System.out.println("Stack Underflow");
        } else
            top--;
    }

    char peek() {
        if (top > -1) {
            return stack[top];
        } else {
            System.out.println("Stack Underflow");
            return 0;
        }
    }

    void bracketMatch(String inputString) {
        char[] charArray = inputString.toCharArray();
        int flag = 1;

        for (int i = 0; i < charArray.length; i++) {
            if (charArray[i] == '(' || charArray[i] == '[' || charArray[i] == '{') {
                this.push(charArray[i]);
            } else if (charArray[i] == ')') {
                if (this.peek() == '(') {
                    this.pop();
                } else {
                    flag = 0;
                    break;
                }
            } else if (charArray[i] == '}') {
                if (this.peek() == '{') {
                    this.pop();
                } else {
                    flag = 0;
                    break;
                }
            } else if (charArray[i] == ']') {
                if (this.peek() == '[') {
                    this.pop();
                } else {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 1 && top == -1) {
            System.out.println("Balanced brackets");
        } else {
            System.out.println("Unbalanced brackets");
        }
    }
}

class q4 {
    public static void main(String args[]) {
        MinimumStack obj = new MinimumStack();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the expression to be verified: ");
        String value = sc.nextLine();
        obj.bracketMatch(value);
    }
}
