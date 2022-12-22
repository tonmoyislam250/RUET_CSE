import java.util.ArrayList;

public class solve {
    public static void main(String[] args) {
        ArrayList<Integer> ax = new ArrayList<>();
        ax.add(10);
        ax.add(50);
        ax.add(70);
        ax.add(30);
        System.out.println(ax);
        ax.add(0, 60);
        System.out.println(ax);
        System.out.println(ax.get(1));
        ax.remove(2);
        System.out.println(ax);
        ax.remove(Integer.valueOf(10));
        System.out.println(ax);
        ax.sort(null);
        for (int i : ax)
            System.out.print(i + " ");
        System.out.print("\n");
        ax.clear();
    }
}
