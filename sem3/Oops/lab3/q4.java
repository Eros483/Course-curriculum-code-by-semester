public class q4{
    public static void main(String[] args){
        Fan f1=new Fan();
        f1.setSpeed(Fan.FAST);
        f1.setRadius(10);
        f1.setColor("yellow");
        f1.setOn(true);
        System.out.println(f1.tostring());

        Fan f2=new Fan();
        f2.setSpeed(Fan.MEDIUM);
        f2.setRadius(5);
        f2.setColor("blue");
        System.out.println(f2.tostring());
    }
}

class Fan{
    public static final int SLOW=1;
    public static final int MEDIUM=2;
    public static final int FAST=3;

    private int speed;
    public int getSpeed(){
        return speed;
    }
    public void setSpeed(int speed){
        this.speed = speed;
    }

    private boolean on;
    public boolean isOn(){
        return on;
    }
    public void setOn(boolean on){
        this.on = on;
    }

    private double radius;
    public double getRadius(){
        return radius;
    }
    public void setRadius(double radius){
        this.radius = radius;
    }

    private String color;
    public String getColor(){
        return color;
    }
    public void setColor(String color){
        this.color = color;
    }

    Fan(){
        this.speed=SLOW;
        this.on=false;
        this.radius=5;
        this.color="Blue";
    }

    public String tostring(){
        if (this.isOn()){
            String string=speed + " " + color+ " " +radius+ " " ;
            return string;
        }

        else{
            String string=color+ " " +radius+ " " +"fan is off";
            return string;
        }
    }

}