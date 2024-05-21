// GCD of two non-negative integers using Repeated Subtraction algorithm.

#include <stdio.h>

// Function to find the greatest common divisor of two non-negative integers using Repeated Subtraction algorithm.
/*
// Recursive approach
int greatestCommonDivisor(int m, int n) {
    if (m == n) {
        return m;
    }
    if (m > n)
        return greatestCommonDivisor(m - n, n);
    return greatestCommonDivisor(m, n - m);
}
*/

// Iterative approach
int greatestCommonDivisor(int m, int n) {
    int a = m, b = n, iterations = 0;
    while (m != n) {
        if (m > n)
            m = m - n;
        else
            n = n - m;
        iterations++;
    }
    printf("\nTo find the greatest common divisor, %d iterations occurred.\n", iterations + 1);
    return m;
}

// Driver code
int main() {
    int m, n, HCF;
    printf("\nEnter a number: ");
    scanf("%d", &m);
    printf("Enter another number: ");
    scanf("%d", &n);
    HCF = greatestCommonDivisor(m, n);
    printf("\nThe greatest common divisor of %d and %d is %d.\n", m, n, HCF);
    return 0;
}

