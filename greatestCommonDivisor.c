/*
Program to find the greatest common divisor using different algorithms such as
Euclid's, Consecutive Integer Checking, Repeated Subtraction and Middle School Method algorithms.
*/

#include <stdio.h>

// Function to find the greatest common divisor of two non-negative integers using Euclid's algorithm.
void euclids(int m, int n) {
    int a = m, b = n;
    int remainder, iterations = 0;
    while (n != 0) {
        remainder = m%n;
        m = n;
        n = remainder;
        iterations++;
    }
    printf("\nUsing Euclid's Algorithm,\nThe greatest common divisor of %d and %d is %d.", a, b, m);
    printf("\nTo find the greatest common divisor, %d iterations occurred.\n", iterations + 1);
}

// Function to find the greatest common divisor of two non-negative integers using Consecutive Integer Checking algorithm.
void consecutiveIntegerChecking(int m, int n, int t) {
    int iterations = 0;
    while (t > 0) {
        if (m % t == 0 && n % t == 0) {
            break;
        } else {
            t--;
            iterations++;
        }
    }
    printf("\nUsing Consecutive Integer Checking Algorithm,\nThe greatest common divisor of %d and %d is %d.", m, n, t);
    printf("\nTo find the greatest common divisor, %d iterations occurred.\n", iterations + 1);
}

// Function to find the greatest common divisor of two non-negative integers using Repeated Subtraction algorithm.
void repeatedSubtraction(int m, int n) {
    int a = m, b = n, iterations = 0;
    while (m != n) {
        if (m > n)
            m = m - n;
        else
            n = n - m;
        iterations++;
    }
    printf("\nUsing Repeated Subtraction Algorithm,\nThe greatest common divisor of %d and %d is %d.", a, b, m);
    printf("\nTo find the greatest common divisor, %d iterations occurred.\n", iterations + 1);
}

// Driver code
int main() {
    int t, m, n;
    printf("\nEnter a number: ");
    scanf("%d", &m);
    printf("Enter another number: ");
    scanf("%d", &n);
    t = (m > n)? n : m;
    if (m > n)
        euclids(m, n);
    else
        euclids(n, m);
    consecutiveIntegerChecking(m, n, t);
    repeatedSubtraction(m, n);
    return 0;
}
