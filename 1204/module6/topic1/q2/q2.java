import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        int a = 0, b = 0;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 2 values : ");
        a = input.nextInt();
        b = input.nextInt();
        if (a > b) {
            System.out.println("The Bigger value is : " + a);
        } else {
            System.out.println("The Bigger Value is : " + b);
        }
        input.close();
    }
}
