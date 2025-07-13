public class q3{
    public static void main(String[] args) {
        int n = 4;
        Share share = new Share();
        Numbers numbers = new Numbers(n, share);
        NumberAndAlphabets numberAndAlphabets = new NumberAndAlphabets(n, share);
        Thread t1 = new Thread(numbers);
        Thread t2 = new Thread(numberAndAlphabets);
        t1.start();
        t2.start();
    }
}
class Share{
    private boolean flag = true;

   public synchronized void printNumber(int n){
        while(!flag){
            try{
                wait();
            }catch(InterruptedException e){
                System.out.println("Thread interrupted"+e);
            }
        }
        for (int i = 1; i < n; i++) {
            System.out.println(i);
        }
        flag = false;
        notifyAll();
   }
   public synchronized void printAlphabet(int n){
    char alphabet = (char) ('A' + (n - 1));
    while(flag){
        try{
            wait();
        }catch(InterruptedException e){
            System.out.println("Thread interrupted"+e);
        }
    }
    System.out.println(n + "    " + alphabet);
    flag = true;
    notifyAll();
}
}
class NumberAndAlphabets implements Runnable{
    private int n;
    private Share share;

    public NumberAndAlphabets(int n , Share share){
        this.n = n;
        this.share = share;
    }

    @Override
    public void run(){
        for(int i = 1 ; i <= n ; i++){
            share.printAlphabet(i);
        }
    }
}

class Numbers implements Runnable{
    private int n;    
    private Share share;

    public Numbers(int n, Share share){
        this.n = n;
        this.share = share;
    }
    @Override
    public void run(){
        for(int i = 1; i <= n ; i++){
            share.printNumber(i);
        }
    }
}
