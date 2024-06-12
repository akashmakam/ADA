import java.util.*;

public class stringMatchingTester {
    int count = 0;
    String text, pattern;
    void read() {
        Scanner in = new Scanner(System.in);
        System.out.print("\nEnter the text: ");
        text = in.nextLine();

        System.out.print("\nEnter the pattern to be searched in the text: ");
        pattern = in.nextLine();
    }

    void stringMatching() {
        int found = 0;

        char[] t = text.toCharArray();
        char[] p = pattern.toCharArray();

        int m = t.length, n = p.length, count = 0;
    
        for (int i = 0; i <= (m - n); i++) {
            count++;
            int j = 0;
            while ((j < n) && (t[i + j] == p[j])) {
                j++;
                count++;
            }
            if (j == n) {
                System.out.println(pattern + " is present in " + text + "! This took " + count + " comparisions.\n");
                found = 1;
                break;
            }
        }
        if (found == 0) {
            System.out.println(pattern + " is not present in " + text + "! This took " + count + " comparisions.\n");
        }
    }
    public static void main(String[] args) {
        stringMatchingTester A = new stringMatchingTester();
        A.read();
        A.stringMatching();
    }
}
