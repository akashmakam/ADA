#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int *array, int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int j = i - 1, key = array[i];
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            count++;
        }
        array[j + 1] = key;
        count++;
    }
    return count;
}

void tester() {
    int n, count;
    printf("\nEnter the number of elements of the array: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    count = insertionSort(array, n);
    printf("Using insertion sort algorithm, %d passes were required to sort the array.\n", count);
}

void plotter() {
    srand(time(NULL));
    int *array, n = 10, count;
    FILE *insertionBest, *insertionWorst, *insertionAverage;

    insertionBest = fopen("insertionBest.txt", "w");
    insertionWorst = fopen("insertionWorst.txt", "w");
    insertionAverage = fopen("insertionAverage.txt", "w");

    while (n <= 30000) {
        array = (int *)malloc(n * sizeof(int));

        // Best case
        for (int i = 0; i < n; i++)
            array[i] = i + 1;
        count = insertionSort(array, n);
        fprintf(insertionBest, "%d\t%d\n", n, count);

        // Worst case
        for (int i = 0; i < n; i++)
            array[i] = n - i;
        count = insertionSort(array, n);
        fprintf(insertionWorst, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++)
            array[i] = rand() % n;
        count = insertionSort(array, n);
        fprintf(insertionAverage, "%d\t%d\n", n, count);

        if (n < 10000)
            n *= 10;
        else
            n += 10000;

        free(array);
    }

    fclose(insertionBest);
    fclose(insertionWorst);
    fclose(insertionAverage);

    printf("\nGNU plot file contents ready for Insertion Sort!\n");
}

int main() {
    int option;
    printf("\nChoose any one of the following:\n"
    "1. Tester\n"
    "2. Plotter\n"
    "3. Exit\n");
    scanf("%d", &option);
    switch(option) {
        case 1: tester(); break;
        case 2: plotter(); break;
        case 3: exit(0);
        default: printf("\nInvalid option!\n");
    }
    return 0;
}