class q2{
    public static void main(String[] args){
        Triangle t1=new Triangle();
        Triangle t2=new Triangle();

        t1.sideA=4;
        t1.sideB=5;
        t1.sideC=6;

        System.out.println("Area of first triangle is: " + t1.getArea());
        System.out.println("Perimeter of first triangle is: " + t1.getPerimeter());

        t2.sideA=1.5;
        t2.sideB=2.5;
        t2.sideC=3.5;
        System.out.println("Area of second triangle is: " + t2.getArea());
        System.out.println("Perimeter of second triangle is: " + t2.getPerimeter());
    }
}

class Triangle{
    double sideA;
    double sideB;
    double sideC;

    Triangle(){
        this.sideA = 1;
        this.sideB = 1;
        this.sideC = 1;
    }

    Triangle(double sideA, double sideB, double sideC){
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
    }

    public double getSideA(){
        return sideA;
    }

    public double getSideB(){
        return sideB;
    }

    public double getSideC(){
        return sideC;
    }

    public void setSideA(double sideA){
        this.sideA = sideA;
    }

    public void setSideB(double sideB){
        this.sideB = sideB;
    }

    public void setSideC(double sideC){
        this.sideC = sideC;
    }

    public double getArea() {
        double s = (sideA + sideB + sideC) / 2;
        return Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    public double getPerimeter() {
        return sideA + sideB + sideC;
    }
}