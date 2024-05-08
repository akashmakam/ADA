// GCD of two non-negative integers using Consecutive Integer Checking Algorithm.

#include <stdio.h>

// Function to find the greatest common divisor of two non-negative integers using consecutive integer checking.
/*
// Recursive approach
int greatestCommonDivisor(int m, int n, int t) {
    if (m % t == 0 && n % t == 0) {
        return t;
    } else {
        return greatestCommonDivisor(m, n, t - 1);
    }
}
*/

// Iterative approach
int greatestCommonDivisor(int m, int n, int t) {
    int iterations = 0;
    while (t > 0) {
        if (m % t == 0 && n % t == 0) {
            printf("\nTo find the greatest common divisor, %d iterations occurred.", iterations);
            return t;
        } else {
            t--;
            iterations++;
        }
    }
    return -1;
}

// Driver code
int main() {
    int t, m, n, HCF;
    printf("\nEnter a number: ");
    scanf("%d", &m);
    printf("Enter another number: ");
    scanf("%d", &n);
    t = (m > n)? n : m;
    HCF = greatestCommonDivisor(m, n, t);
    printf("\nThe greatest common divisor of %d and %d is %d.\n", m, n, HCF);
    return 0;
}