class A {
    int x;

    public A() {
        x = 0;
    }

    public A(int x) {
        this.x = x;
    }

    public int getX() {
        return (x + 10);
    }
}

class B extends A {
    int x = 20;

    public B() {
        super(100);
    }

    public int Ax() {
        return super.x;
    }

    public int getXA() {
        return super.getX();
    }

    public int getX() {
        return (x + 10);
    }
}

public class solve {
    public static void main(String[] args) {
        B test = new B();
        System.out.println("the x of class A is ; " + test.Ax());
        System.out.println("The getx of A is : " + test.getXA());
        System.out.println("The x of class B : " + test.x);
        System.out.println("The getx of classs B : " + test.getX());
    }
}
