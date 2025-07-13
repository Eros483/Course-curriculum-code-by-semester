public class q2 {
    public static void main(String[] args) {
        classCounter c1=new classCounter();

        classCounter.show_count();

        classCounter c2=new classCounter();
        classCounter c3=new classCounter();

        classCounter.show_count();
    }
}

class classCounter{
    static int count=0;
    classCounter(){
        count++;
    }

    static void show_count(){
        System.out.println(count);
    }
}