#include <stdio.h>
#include <stdlib.h>

int count = 0;

int* read(int *n) {
    printf("\nEnter the size of the array: ");
    scanf("%d", n);

    int *array = (int *)malloc((*n) * sizeof(int));
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

void display(int *array, int n) {
    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int partition(int *array, int start, int end) {
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        count++;
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;

    return i + 1;
}

void quickSort(int *array, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, end);
    }
}

void plotter() {
    FILE *f1, *f2;

    f1 = fopen("quickBest.txt", "w");
    f2 = fopen("quickWorst.txt", "w");

    for (int n = 2; n <= 1024; n = n * 2) {
        int *array = (int *)malloc(n * sizeof(int));

        // Best case
        count = 0;
        for (int i = 0; i < n; i++) {
            array[i] = 1;
        }
        quickSort(array, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count);
        
        // Worst case
        count = 0;
        for (int i = 0; i < n; i++) {
            array[i] = i + 1;
        }
        quickSort(array, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count);

        free(array);
    }

    fclose(f1);
    fclose(f2);
}

void tester() {
    int n;
    int *array = read(&n);
    quickSort(array, 0, n - 1);
    display(array, n);
    printf("\nThis took %d comparisons.\n", count);
    free(array);
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