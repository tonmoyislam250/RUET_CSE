package q2;

import q1.*;

public class q2 extends q1 {
    public static void main(String[] args) {
        System.out.println("Hello from subclass outside the package");
        q2.hello();
        // The method hello2() from the type q1 is not visible
        // q2.hello2();
        q2.hello3();
        // The method hello4() from the type q1 is not visible
        // q2.hello4();
    }
}

class q21 {
    public static void main(String[] args) {
        q1.hello();
        // The method hello2() from the type q1 is not visible
        // q1.hello2();
        // The method hello3() from the type q1 is not visible
        // q1.hello3();
        // The method hello4() from the type q1 is not visible
        // q1.hello4();
    }
}
