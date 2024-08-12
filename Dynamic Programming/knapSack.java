import java.util.*;

class knapSack {
    static void display(int[][] array, int noOfItems, int totalCapacity) {
        System.out.print("\nThe knapsack table using dynamic programming is as follows:\n");
        for (int i = 0; i <= noOfItems; i++) {
            for (int w = 0; w <= totalCapacity; w++) {
                System.out.print(array[i][w] + "\t");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("\nEnter the number of items in the knapsack problem: ");
        int noOfItems = in.nextInt();
        System.out.print("Enter the total capacity of the knapsack problem: ");
        int totalCapacity = in.nextInt();
        
        int[] weightOfItems = new int[noOfItems];
        int[] profitOfItems = new int[noOfItems];
        
        System.out.println("\nEnter the corresponding weights for each item:");
        for (int i = 0; i < noOfItems; i++) {
            weightOfItems[i] = in.nextInt();
        }

        System.out.println("\nEnter the corresponding profits for each item:");
        for (int i = 0; i < noOfItems; i++) {
            profitOfItems[i] = in.nextInt();
        }

        System.out.println("\nThe entered data is as follows:\nItem\tWeight\tProfit");
        for (int i = 0; i < noOfItems; i++) {
            System.out.println(i + 1 + "\t" + weightOfItems[i] + "\t" + profitOfItems[i]);
        }

        int[][] knapSackArray = new int[noOfItems + 1][totalCapacity + 1];

        for (int i = 0; i < noOfItems; i++) {
            knapSackArray[i][0] = 0;
        }

        for (int j = 0; j < totalCapacity; j++) {
            knapSackArray[0][j] = 0;
        }

        System.out.println("\nSteps:");

        for (int i = 1; i <= noOfItems; i++) {
            for (int j = 1; j <= totalCapacity; j++) {
                if (weightOfItems[i - 1] <= j) {
                    knapSackArray[i][j] = Math.max(knapSackArray[i - 1][j],
                            knapSackArray[i - 1][j - weightOfItems[i - 1]] + profitOfItems[i - 1]);
                } else {
                    knapSackArray[i][j] = knapSackArray[i - 1][j];
                }
            }
        }

        display(knapSackArray, noOfItems, totalCapacity);
        
        System.out.println("\nMaximum profit is: " + knapSackArray[noOfItems][totalCapacity]);
        in.close();
    }
}