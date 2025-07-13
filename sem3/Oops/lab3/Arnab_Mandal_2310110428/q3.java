public class q3 {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[6];

        shapes[0] = new Circle(5);
        shapes[1] = new Rectangle(4, 6);
        shapes[2] = new Triangle(3, 4, 5);
        shapes[3] = new Sphere(5);
        shapes[4] = new Cube(3);
        shapes[5] = new Tetrahedron(4);

        for (Shape shape : shapes) {
            if (shape instanceof TwoDimensionalShape) {
                System.out.println("This is a Two-Dimensional Shape." + "\n");

                if (shape instanceof Circle) {
                    System.out.println("This is a Circle Shape." + "\n");
                }

                if (shape instanceof Rectangle) {
                    System.out.println("This is a Rectangle Shape." + "\n");
                }

                if (shape instanceof Triangle) {
                    System.out.println("This is a Triangle Shape." + "\n");
                }

                System.out.println("Area: " + shape.getArea());

            } else if (shape instanceof ThreeDimensionalShape) {
                System.out.println("This is a Three-Dimensional Shape." + "\n");

                if (shape instanceof Cube) {
                    System.out.println("This is a Cube Shape." + "\n");
                }

                if (shape instanceof Tetrahedron) {
                    System.out.println("This is a Tetrahedron Shape." + "\n");
                }

                if (shape instanceof Sphere) {
                    System.out.println("This is a Sphere Shape." + "\n");
                }

                System.out.println("Area: " + shape.getArea());
                System.out.println("Volume: " + shape.getVolume());
            }
        }
    }
}

class Shape{
    //parent class
    double getArea(){
        return 0;
    }

    double getVolume(){
        return 0;
    }
}

class TwoDimensionalShape extends Shape{
    double getArea(){
        return 0;
    }
}

class Circle extends TwoDimensionalShape{
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends TwoDimensionalShape {
    private double length;
    private double breadth;

    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public double getLength() {
        return length;
    }

    public double getBreadth() {
        return breadth;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public void setBreadth(double breadth) {
        this.breadth = breadth;
    }

    public double getArea() {
        return length * breadth;
    }
}

class Triangle extends TwoDimensionalShape {
    private double sideA;
    private double sideB;
    private double sideC;

    public Triangle(double sideA, double sideB, double sideC) {
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
    }

    public double getSideA() {
        return sideA;
    }

    public double getSideB() {
        return sideB;
    }

    public double getSideC() {
        return sideC;
    }

    public void setSideA(double sideA) {
        this.sideA = sideA;
    }

    public void setSideB(double sideB) {
        this.sideB = sideB;
    }

    public void setSideC(double sideC) {
        this.sideC = sideC;
    }

    public double getArea() {
        double s = (sideA + sideB + sideC) / 2;
        return Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
}

class ThreeDimensionalShape extends Shape{
    double getVolume() {
        return 0;
    }
}

class Sphere extends ThreeDimensionalShape{
    private double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return 4 * Math.PI * radius * radius;
    }

    public double getVolume() {
        return (4.0 / 3) * Math.PI * Math.pow(radius, 3);
    }
}

class Cube extends ThreeDimensionalShape {
    private double side;

    public Cube(double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        this.side = side;
    }

    @Override
    public double getArea() {
        // Surface area of a cube: 6 * side^2
        return 6 * side * side;
    }

    public double getVolume() {
        // Volume of a cube: side^3
        return Math.pow(side, 3);
    }
}

class Tetrahedron extends ThreeDimensionalShape {
    private double side;

    public Tetrahedron(double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        this.side = side;
    }

    public double getArea() {
        return Math.sqrt(3) * side * side;
    }

    public double getVolume() {
        return Math.pow(side, 3) / (6 * Math.sqrt(2));
    }
}

