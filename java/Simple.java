import java.util.Scanner;

import java.util.*;

class Simple {
    public static void main(String[] args) {
        System.out.println("Hello World !");
        int a = 0, b = 0, c = 0;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the sides of the triangle : ");
        in.nextInt(a);
        in.nextInt(b);
        in.nextInt(c);
        int s = (a + b + c) / 2;
        System.out.println("Perimeter is : " + s);
    }
}