#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selectionSort(int *array, int n) {
    int count = 0, min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            count++;
            if (array[min] > array[j])
                min = j;
        }
        if (min != i) {
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
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
    count = selectionSort(array, n);
    printf("Using selection sort algorithm, %d passes were required to sort the array.\n", count);
}

void plotter() {
    srand(time(NULL));
    int *array, n = 10, count;
    FILE *selectionGeneral;

    selectionGeneral = fopen("selectionGeneral.txt", "w");

    while (n <= 30000) {
        array = (int *)malloc(n * sizeof(int));

        // General case
        for (int i = 0; i < n; i++)
            array[i] = rand() % n;
        count = selectionSort(array, n);
        fprintf(selectionGeneral, "%d\t%d\n", n, count);

        if (n < 10000)
            n *= 10;
        else
            n += 10000;

        free(array);
    }

    fclose(selectionGeneral);

    printf("\nGNU plot file contents ready for Selection Sort!\n");
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