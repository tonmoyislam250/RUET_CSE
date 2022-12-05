package java1;
public class simle{
    public static void main(String[] arg){
        System.out.println("Hello World");
        A a = new A();
        a.display();
    }
}
class A{
    public int x=10;
    protected int y=20;
    int z=30;
    private int w=40;
     public void display() {
        System.out.println("x = "+x);
        System.out.println("y = "+y);
        System.out.println("y = "+z);
        System.out.println("w = "+w);
     }
}