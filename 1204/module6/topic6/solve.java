import java.util.Arrays;

public class solve {
    public static int[] Initarray() {
        return new int[] { 5, 4, 3, 2, 1, 7, 6, 9 };
    }

    public static int[] sortedArray(int[] arr) {
        Arrays.sort(arr);
        return arr;
    }

    public static void PrintArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        int[] h = Initarray();
        System.out.println("Before Sorting : ");
        PrintArray(h);
        int[] m = sortedArray(h);
        System.out.println("\nAfter Sorting : ");
        PrintArray(m);
        System.out.print("\n");
    }
}
