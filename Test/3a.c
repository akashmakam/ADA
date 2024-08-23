#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int *array, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            count++;
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
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
    count = bubbleSort(array, n);
    printf("Using bubble sort algorithm, %d passes were required to sort the array.\n", count);
}

void plotter() {
    srand(time(NULL));
    int *array, n = 10, count;
    FILE *bubbleBest, *bubbleWorst, *bubbleAverage;
    bubbleBest = fopen("bubbleBest.txt", "w");
    bubbleWorst = fopen("bubbleWorst.txt", "w");
    bubbleAverage = fopen("bubbleAverage.txt", "w");
    while (n <= 30000) {
        array = (int *)malloc(n * sizeof(int));
        // Best case
        for (int i = 0; i < n; i++)
            array[i] = i + 1;
        count = bubbleSort(array, n);
        fprintf(bubbleBest, "%d\t%d\n", n, count);
        // Worst case
        for (int i = 0; i < n; i++)
            array[i] = n - i;
        count = bubbleSort(array, n);
        fprintf(bubbleWorst, "%d\t%d\n", n, count);
        // Average case
        for (int i = 0; i < n; i++)
            array[i] = rand() % n;
        count = bubbleSort(array, n);
        fprintf(bubbleAverage, "%d\t%d\n", n, count);
        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        free(array);
    }
    fclose(bubbleBest);
    fclose(bubbleWorst);
    fclose(bubbleAverage);
    printf("\nGNU plot file contents ready for Bubble Sort!\n");
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