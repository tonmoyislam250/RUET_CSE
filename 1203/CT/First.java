package CT;

import java.util.ArrayList;

public class First {
    public static void main(String[] args) {
        System.out.println("INside MAin()");
        ArrayList<String> list = new ArrayList<>();
        list.add("Mango");
        list.add("Pineapple");
        list.add("Apple");
        list.sort(null);
        System.out.println(list.toString());
        for (String i : list) {
            System.out.print(i + " ");
        }
        System.out.println();
        // A.B  a = new A.B(21);
        String s = "Tonmoy";
        String m = "####";
        System.out.println(s.charAt(0));
        System.out.println(s.equals(m));
        A.B b = new A().new B(12);
        System.out.println(b.getSum());
    }
}

class A {
    private int x = 10;

    public class B {
        private int y;

        public B(int y) {
            this.y = y;
        }

        public int gety() {
            return y;
        }

        public int getSum() {
            return x + y;
        }
    }
}

class Outer {
    private int x = 20;

    public class Inner {
        private int y;

        public Inner(int y) {
            this.y = y;
        }

        public void setY(int y) {
            this.y = y;
        }

        public int getY() {
            return y;
        }

        public void sum() {
            System.out.println("inside sum=" + (x + y));
        }
    }

    public void Display() {
        Inner inner = new Inner(0);
        inner.setY(12);
        System.out.println(inner.getY());
    }
}