// Insertion Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void read(int *array, int n) {
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void display(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

// Insertion sort function with comparison counting
int insertionSort(int *array, int n) {
    int comparisonCount = 0;  // Initialize comparison counter

    printf("\nSteps:\n");
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        // Move elements of array[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            comparisonCount++;
        }
        // If the while loop did not execute, we still need to count the comparison where array[j] <= key
        if (j >= 0) {
            comparisonCount++;
        }

        array[j + 1] = key;  // Place key at the correct position

        // Print the current state of the array
        printf("%d. ", comparisonCount);
        display(array, n);
    }
    return comparisonCount;  // Return total number of comparisons
}

void tester() {
    int n, count;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    read(array, n);
    printf("\nThe elements of the array are:\n");
    display(array, n);
    count = insertionSort(array, n);
    printf("\nThe sorted elements of the array are:\n");
    display(array, n);
    printf("Number of comparisons: %d\n", count);
}

void plotter() {
    srand(time(NULL));
    int *array, n = 10, count;
    FILE *f1, *f2, *f3;
    f1 = fopen("insertionBest.txt", "w");
    f2 = fopen("insertionWorst.txt", "w");
    f3 = fopen("insertionAverage.txt", "w");
    while (n <= 30000) {
        array = (int *)malloc(n * sizeof(int));

        // Best case
        for (int i = 0; i < n; i++)
            array[i] = i + 1;
        count = insertionSort(array, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst case
        for (int i = 0; i < n; i++)
            array[i] = n - i;
        count = insertionSort(array, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++)
            array[i] = rand() % n;
        count = insertionSort(array, n);
        fprintf(f3, "%d\t%d\n", n, count);

        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        free(array);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("\nGNU plot file contents ready!\n");
}

// Driver Code
int main() {
    int option;
    do {
        printf("\nChoose any one of the following:\n"
        "1. Tester\n"
        "2. Plotter\n"
        "3. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1: tester(); break;
            case 2: plotter(); break;
            case 3: return 0;
            default: printf("Invalid option!\n");
        }
    } while (option != 3);
    return 0;
}