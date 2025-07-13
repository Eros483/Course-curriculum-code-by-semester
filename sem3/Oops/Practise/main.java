class P {
    public static void m() {
        System.out.println("C++");
    }
}

class C extends P {
    public static void m() {
        System.out.println("Java");
    }
}

public class main {
    public static void main(String[] args) {
        P p = new C();
        p.m();
    }
}