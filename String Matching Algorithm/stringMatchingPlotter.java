import java.util.*;
import java.io.IOException;
import java.io.FileWriter;

public class stringMatchingPlotter {
    int count;

    void stringMatching(char[] text, char[] pattern) {
        int m = text.length, n = pattern.length;
        count = 0;
        String t = String.valueOf(text);
        String p = String.valueOf(pattern);
    
        for (int i = 0; i <= (m - n); i++) {
            count++;
            int j = 0;
            while ((j < n) && (text[i + j] == pattern[j])) {
                j++;
                count++;
            }
            if (j == n) {
                break;
            }
        }
    }
    public static void main(String[] args) {
        stringMatchingPlotter A = new stringMatchingPlotter();
        Random random = new Random();
        try {
            FileWriter bestCase = new FileWriter("stringBest.txt");
            FileWriter worstCase = new FileWriter("stringWorst.txt");
            FileWriter averageCase = new FileWriter("stringAverage.txt");
            int m = 1000, n = 10;
            char[] text = new char[m];
            for (int i = 0; i < m; i++)
                text[i] = 'a';
            while (n <= m) {
                char[] pattern = new char[n];

                // Best case
                A.count = 0;
                for (int i = 0; i < n; i++)
                    pattern[i] = 'a';
                A.stringMatching(text, pattern);
                bestCase.write(n + "\t" + A.count + "\n");

                // Worst case
                A.count = 0;
                pattern[n - 1] = 'b';
                A.stringMatching(text, pattern);
                worstCase.write(n + "\t" + A.count + "\n");

                // Average case
                A.count = 0;
                for (int i = 0; i < n; i++) 
                    pattern[i] = (char)(97 + random.nextInt(3));
                A.stringMatching(text, pattern);
                averageCase.write(n + "\t" + A.count + "\n");

                n = (n < 100)? (n += 10): (n += 100);
            }
            bestCase.close();
            worstCase.close();
            averageCase.close();
        } catch (IOException e) {
            System.out.println("An error has occurred.");
            e.printStackTrace();
        }
    }
}
