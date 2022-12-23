package q1;

public class q1Two {
    public static void main(String[] args) {
        System.out.println("Hello World from another class within package");
        q1.hello();
        // The method hello2() from the type q1 is not visible
        // q1.hello2();
        q1.hello3();
        q1.hello4();
    }
}
