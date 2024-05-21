/*
Program to find the greatest common divisor using different algorithms such as
Euclid's, Consecutive Integer Checking, and Repeated Subtraction Procedure algorithms.
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
void consecutiveIntegerChecking(int m, int n) {
    int iterations = 0;
    int t = (m > n)? n : m;
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
    int m, n, option;
    printf("\nEnter a number: ");
    scanf("%d", &m);
    printf("Enter another number: ");
    scanf("%d", &n);
    do {
        printf("\nCalculate GCD:\n"
        "1. Euclid's Algorithm\n"
        "2. Consecutive Integer Checking\n"
        "3. Modified Euclid's Algorithm\n"
        "4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                if (m > n)
                    euclids(m, n);
                else
                    euclids(n, m);
                break;
            case 2:
                consecutiveIntegerChecking(m, n);
                break;
            case 3:
                repeatedSubtraction(m, n);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while (option != 4);
    return 0;
}
