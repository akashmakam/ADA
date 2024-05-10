// GCD of two non-negative integers using Euclid's algorithm.

#include <stdio.h>

// Function to find the greatest common divisor(GCD) of two non-negative integers.
/*
// Recursive approach
int greatestCommonDivisor(int m, int n) {
    if (n == 0) {
        return m;
    }
    return greatestCommonDivisor(n, m%n);
}
*/

// Iterative approach
int greatestCommonDivisor(int m, int n) {
    int remainder, iterations = 0;
    while (n != 0) {
        remainder = m%n;
        m = n;
        n = remainder;
        iterations++;
    }
    printf("\nTo find the greatest common divisor, %d iterations occurred.", iterations + 1);
    return m;
}

// Driver code
int main() {
    int m, n, HCF;
    printf("\nEnter a number: ");
    scanf("%d", &m);
    printf("Enter another number: ");
    scanf("%d", &n);
    HCF = (m > n)? greatestCommonDivisor(m, n) : greatestCommonDivisor(n, m);
    printf("\nThe greatest common divisor of %d and %d is %d.\n", m, n, HCF);
    return 0;
}