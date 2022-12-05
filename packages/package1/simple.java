package package1;
import java.util.Scanner;

public class simple {
    public static void main(String[] arg) {
        System.out.println("Welcome to Java");
        Scanner input = new Scanner(System.in);
        int a,b,c;
        System.out.print("Enter a,b,c : ");
        a=input.nextInt();
        b=input.nextInt();
        c=input.nextInt();
        System.out.println("a= "+a+"b= "+b+"c= "+c);
        input.close();
    }
}
