class MinimumStack{
    int stack[] = new int[10];
    int top;

    MinimumStack(){
        top = -1;
    }

    // Push an item onto the stack
    void push(int item){
        if(top==9)
            System.out.println("Stack is full");
        else
            stack[++top] = item;
    }

    // Pop an item from the stack
    void pop(){
        if(top < 0) {
            System.out.println("Stack Underflow");
        }
        else
            top--;
    }

    int peek(){
        if (top>-1){
            return stack[top];
        }
        else{
            System.out.println("Stack Underflow");
            return 0;
        }
    }

    int top(){
        if (top>-1){
            return stack[top--];
        }
        else{
            System.out.println("Stack Underflow");
            return 0;
        }
    }

    int getMin(){
        int min;
        if (top>-1){
            min = stack[top];
            for (int i=top-1; i>=0; i--){
                if (min>stack[i]){
                    min = stack[i];
                }
            }
            return min;
        }

        else{
            System.out.println("Stack Underflow");
            return 0;
        }
    }
}

class q3{
    public static void main(String args[]){
        MinimumStack obj = new MinimumStack();
        obj.push(1);
        System.out.println(obj.peek());
        obj.push(2);
        obj.push(3);
        System.out.println(obj.peek());
        obj.pop();
        obj.pop();
        System.out.println(obj.peek());
        obj.push(4);
        obj.push(2);
        System.out.println(obj.getMin());
        System.out.println(obj.top());
        obj.pop();
        System.out.println(obj.getMin());

    }
}