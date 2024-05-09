// Generation of prime numbers from 2 to 'n' using the Sieve of Eratosthenes Algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate the list of prime numbers from 2 to 'n'.
void sieveOfEratosthenes(int n) {
    int *array = malloc((n + 1) * sizeof(int));
    if (array == NULL) {
        printf("\nMemory could not be dynamically allocated for the array!\n");
        exit(1);
    }
    for(int i = 2; i <= n; i++)
        array[i] = i;

    for (int i = 2; i <= sqrt(n); i++) {
        if(array[i] != 0) {
            for (int j = i*i; j <= n; j += i) {
                array[j] = 0;
            }
        }
    }
    printf("\nThe prime numbers from 2 to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (array[i] != 0)
            printf("%d\t", array[i]);
    }
    printf("\n");

    free(array);
}

// Driver code
int main() {
    int n;
    printf("\nEnter the range: ");
    scanf("%d", &n);
    while(n < 2) {
        printf("\nInvalid range! Enter a number greater than or equal to 2: ");
        scanf("%d", &n);
    } 
    sieveOfEratosthenes(n);
    return 0;
}