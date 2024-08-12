#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c;

    printf("\nEnter the number of items in the knapsack problem: ");
    scanf("%d", &n);
    printf("Enter the total capacity of the knapsack problem: ");
    scanf("%d", &c);

    int weightOfItems[n];
    int profitOfItems[n];

    printf("\nEnter the corresponding weights for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weightOfItems[i]);
    }

    printf("\nEnter the corresponding profits for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profitOfItems[i]);
    }

    printf("\nThe entered data is as follows:\nItem\tWeight\tProfit\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, weightOfItems[i], profitOfItems[i]);
    }
    printf("\n");
    int knapSackArray[n][c];

    for (int i = 0; i < n; i++) {
        knapSackArray[i][0] = 0;
    }

    for (int j = 0; j < c; j++) {
        knapSackArray[0][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < c; j++) {
            if (weightOfItems[i - 1] <= j) {
                knapSackArray[i][j] = (knapSackArray[i - 1][j] > 
                    (knapSackArray[i - 1][j - weightOfItems[i - 1]] + profitOfItems[i - 1])) ?
                    knapSackArray[i - 1][j] : 
                    (knapSackArray[i - 1][j - weightOfItems[i - 1]] + profitOfItems[i - 1]);
            } else {
                knapSackArray[i][j] = knapSackArray[i - 1][j];
            }
        }
    }

    printf("The knapsack table using dynamic programming is as follows:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            printf("%d\t", knapSackArray[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum profit is: %d\n", knapSackArray[n][c]);

    return 0;
}