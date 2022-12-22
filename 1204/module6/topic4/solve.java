public class solve {
    public static void add(int x, int y) {
        int sum = x + y;
        System.out.println("The sum is " + sum);
    }

    public void add2(int x, int y) {
        int sum = x + y;
        System.out.println("The sum is " + sum);
    }

    public static void main(String[] args) {
        // Cannot make a static reference to the non-static method add2(int, int) from
        // the type solve
        // add2(12, 13);
        add(12, 13);
    }
}