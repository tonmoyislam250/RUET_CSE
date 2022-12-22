interface AI {
    public void printA();
}

interface BI {
    public void printB();
}

interface CI {
    public void printC();
}

class A implements AI {
    public void printA() {
        System.out.println("Print of class A");
    }
}

class B extends A implements BI {
    public void printB() {
        System.out.println("Print class of B");
    }
}

class C extends B implements CI {
    public void printC() {
        System.out.println("Print class of B");
    }
}

public class solve {
    public static void main(String[] args) {
        C test = new C();
        test.printA();
        test.printB();
        test.printC();
    }
}