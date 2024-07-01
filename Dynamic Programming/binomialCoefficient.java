import java.util.Scanner;

class binomialCoefficient {
    int min(int i, int r) {
        return (i < r) ? i : r;
    }
    
    int coefficientFinder(int n, int r) {
        int[][] A = new int[n + 1][r + 1];
        System.out.println("\nMatrix:");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, r); j++) {
                if (j == 0 || j == i) {
                    A[i][j] = 1;
                } else {
                    A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
                }
                System.out.print(A[i][j] + "\t");
            }
            System.out.print("\n");
        }
        System.out.println("\nWorking:");
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, r); j++) {
                if (j == 0 || j == i) {
                    System.out.println("C(" + i + "," + j + ") = 1");
                } else {
                    System.out.println("C(" + i + "," + j + ") = C(" + (i - 1) + "," + (j - 1) + ") + C(" + (i - 1) + "," + (j) + ") = " + A[i][j]);
                }
            }
        }
        return A[n][r];
    }

    public static void main(String[] args) {
        int n, r;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        n = in.nextInt();
        System.out.print("Enter the value of r: ");
        r = in.nextInt();
        binomialCoefficient bc = new binomialCoefficient();
        int coefficient = bc.coefficientFinder(n, r);
        System.out.println("\nBinomial Coefficient C(" + n + "," + r + ") = " + coefficient);
        in.close();
    }
}