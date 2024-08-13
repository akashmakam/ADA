#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum profit using top-down approach (memoization)
int knap(int i, int c, int *w, int *p, int memo[][c + 1]) {
    if (i == 0 || c == 0) {
        return 0;
    }
    if (memo[i][c] != -1) {
        return memo[i][c];
    }
    if (w[i - 1] > c) {
        memo[i][c] = knap(i - 1, c, w, p, memo);
    } else {
        int includeItem = p[i - 1] + knap(i - 1, c - w[i - 1], w, p, memo);
        int excludeItem = knap(i - 1, c, w, p, memo);
        memo[i][c] = (includeItem > excludeItem) ? includeItem : excludeItem;
    }

    return memo[i][c];
}

int main() {
    int n, c;
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    printf("Enter the total capacity: ");
    scanf("%d", &c);

    int w[n], p[n];
    int memo[n + 1][c + 1];

    printf("\nEnter the weight of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("\nEnter the profit of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            memo[i][j] = -1;
        }
    }

    int max = knap(n, c, w, p, memo);
    printf("The maximum profit is %d.\n", max);

    return 0;
}