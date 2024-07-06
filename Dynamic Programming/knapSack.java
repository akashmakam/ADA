import java.util.*;

class knapSack {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("\nEnter the number of items in the knapsack problem: ");
        int noOfItems = in.nextInt();
        System.out.print("Enter the total weight for the knapsack problem: ");
        int maxWeight = in.nextInt();
        
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

        int[][] knapSackArray = new int[noOfItems + 1][maxWeight + 1];

        for (int i = 1; i <= noOfItems; i++) {
            for (int w = 1; w <= maxWeight; w++) {
                if (weightOfItems[i - 1] <= w) {
                    knapSackArray[i][w] = Math.max(knapSackArray[i - 1][w],
                            knapSackArray[i - 1][w - weightOfItems[i - 1]] + profitOfItems[i - 1]);
                } else {
                    knapSackArray[i][w] = knapSackArray[i - 1][w];
                }
            }
        }

        System.out.print("\nThe knapsack table using dynamic programming is as follows:\n");
        for (int i = 0; i <= noOfItems; i++) {
            for (int w = 0; w <= maxWeight; w++) {
                System.out.print(knapSackArray[i][w] + "\t");
            }
            System.out.println();
        }
        
        System.out.println("\nMaximum profit is: " + knapSackArray[noOfItems][maxWeight]);
        in.close();
    }
}