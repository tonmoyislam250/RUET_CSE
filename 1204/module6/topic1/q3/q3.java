import java.util.Scanner;

public class q3 {
    public static void main(String[] args) {
        int[] ax = new int[10];
        int sum = 0;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the array Values: ");
        for (int i = 0; i < 10; i++) {
            ax[i] = s.nextInt();
        }
        int min = ax[0], max = ax[1];
        for (int i = 0; i < 10; i++) {
            if (min > ax[i]) {
                min = ax[i];
            }
            if (ax[i] > max) {
                max = ax[i];
            }
            sum += ax[i];
        }
        System.out.println("The Maximum Value is : " + max);
        System.out.println("The Minimum Value is " + min);
        System.out.println("The Average value is " + sum / 10);
        s.close();
    }
}