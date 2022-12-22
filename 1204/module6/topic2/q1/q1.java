package q1;

public class q1 {
    public static void main(String[] args) {
        System.out.println("Hello world Original");
        hello();
        hello2();
        hello3();
    }

    public static void hello() {
        System.out.println("Hello World in public method within class");
    }

    private static void hello2() {
        System.out.println("Hello World in private method within class");
    }

    protected static void hello3() {
        System.out.println("Hello World in protected method within class");
    }

    static void hello4() {
        System.out.println("Hello World in default method within class");
    }
}
