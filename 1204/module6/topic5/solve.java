public class solve {
    public static void main(String[] args) {
        String h = "Computer", H = "Science";
        System.out.println("The 2 index is " + h.charAt(2));
        System.out.println("the output is " + h.compareTo(H));
        if (h.compareTo(H) < 0) {
            System.out.println("lexicographically less than the other string ");
        }
        System.out.println(h.concat(H));
        if (h.equals(H)) {
            System.out.println("the strings are equal");
        } else {
            System.out.println("the strings are not equal");
        }
        if (h.isEmpty()) {
            System.out.println("the string is empty");
        } else {
            System.out.println("The string is not empty ");
        }
        System.out.println("The Length of The String : " + h.length());
        System.out.println("Replaced r with R : " + h.replace('r', 'R'));
        System.out.println("the substring is : " + h.substring(0, 3));
        System.out.println("The Uppercase is : " + h.toUpperCase());
        System.out.println("The Lowercase is : " + h.toLowerCase());
        System.out.println("The toString is : " + h.toString());
        System.out.println("The trimmed string is " + h.trim());
    }
}
