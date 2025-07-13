public class q1 {
    public static void main(String[] args) {
        Circl2D c1 = new Circl2D(2, 2, 5.5);
        System.out.println(c1.getArea());
        System.out.println(c1.getPerimeter());
        System.out.println("Contains point (3, 3): " + c1.contains(3, 3));

        System.out.println("Contains circle (4, 5, 10.5): " + c1.contains(new Circl2D(4, 5, 10.5)));

        System.out.println("Overlaps with circle (3, 5, 2.3): " + c1.overlaps(new Circl2D(3, 5, 2.3)));
    }
}

class Circl2D {
    double x;
    double y;
    double radius;

    Circl2D() {
        this.x = 0;
        this.y = 0;
        this.radius = 1;
    }

    Circl2D(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    double getPerimeter() {
        return 2 * Math.PI * this.radius;
    }

    boolean contains(double x, double y) {
        double distance = Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
        return distance <= this.radius;
    }

    boolean contains(Circl2D circle) {
        double distance = Math.sqrt(Math.pow(this.x - circle.x, 2) + Math.pow(this.y - circle.y, 2));
        return distance + circle.radius <= this.radius;
    }

    boolean overlaps(Circl2D circle) {
        double distance = Math.sqrt(Math.pow(this.x - circle.x, 2) + Math.pow(this.y - circle.y, 2));
        return distance < (this.radius + circle.radius) && distance > Math.abs(this.radius - circle.radius);
    }
}
