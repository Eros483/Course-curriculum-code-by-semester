public class q6 {
    public static void main(String[] args) {
        long milliseconds = System.currentTimeMillis();

        long seconds = milliseconds / 1000;
        long minutes = seconds / 60;
        long hours = minutes / 60;

        seconds %= 60;
        minutes %= 60;
        hours %= 24;
        String formattedTime = String.format("%02d:%02d:%02d", hours, minutes, seconds);
        System.out.println("time is: " + formattedTime);
    }
}