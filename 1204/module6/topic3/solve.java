public class solve {
    private static void add(int x, int y) {
        int sum = x + y;
        System.out.println("The sum is " + sum);
    }

    public static void main(String[] args) {
        add(12, 13);
    }
}

class solve2 {
    // The method add(int, int) is undefined for the type solve2
    public static void main(String[] args) {
        // add(12, 13);
    }
}