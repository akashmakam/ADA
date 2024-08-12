#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int binarySearch(int *array, int start, int end, int key, int mode) {
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    count++;
    if (key == array[mid]) {
        if (mode == 0)
            printf("The key was found at position %d of the array!\n", mid);
        return mid;
    } else if (key > array[mid])
        return binarySearch(array, mid + 1, end, key, mode);
    else
        return binarySearch(array, start, mid - 1, key, mode);
}

void tester() {
    int n, key;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the key to be searched in the array: ");
    scanf("%d", &key);
    binarySearch(array, 0, n - 1, key, 0);
}

void plotter() {
    srand(time(NULL));
    int n = 2, r;
    FILE *f1 = fopen("binaryBest.txt", "w");
    FILE *f2 = fopen("binaryWorst.txt", "w");
    FILE *f3 = fopen("binaryAverage.txt", "w");
    while (n <= 1024) {
        int *array = (int *) malloc(sizeof(int)*n);

        for (int i = 0; i < n; i++) {
            array[i] = i;
        }
        // Best case
        int mid = (n - 1)/2;
        count = 0;
        r = binarySearch(array, 0, n - 1, array[mid], 1);
        fprintf(f1, "%d %d\n", n, count);

        // Worst case
        count = 0;
        r = binarySearch(array, 0, n - 1, n + 1, 1);
        fprintf(f2, "%d %d\n", n, count);

        // Average case
        count = 0;
        r = binarySearch(array, 0, n - 1, array[n / 2], 1);
        fprintf(f3, "%d %d\n", n, count);
        n *= 2;

        free(array);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
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