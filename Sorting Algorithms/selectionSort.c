// Selection Sort

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

int selectionSort(int *array, int n) {
    int min, count = 0;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            count++;
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    return count;
}

void tester() {
    int n, count;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    read(array, n);
    printf("\nThe elements of the array are:\n");
    display(array, n);
    count = selectionSort(array, n);
    printf("\nThe sorted elements of the array are:\n");
    display(array, n);
    printf("Number of comparisons: %d\n", count);
}

void plotter() {
    srand(time(NULL));
    int *array, n = 10, count;
    FILE *f1;
    f1 = fopen("selectionAverage.txt", "w");
    while (n <= 30000) {
        array = (int *)malloc(n * sizeof(int));

        // Average case
        for (int i = 0; i < n; i++)
            array[i] = rand() % n;
        count = selectionSort(array, n);
        fprintf(f1, "%d\t%d\n", n, count);

        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        free(array);
    }
    fclose(f1);
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