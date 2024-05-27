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

int bubbleSort(int *array, int n) {
    int count = 0, flag;
    for (int i = 0; i < n; i++) {
        flag = 0;
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
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    read(array, n);
    printf("\nThe elements of the array are:\n");
    display(array, n);
    count = bubbleSort(array, n);
    printf("\nThe sorted elements of the array are:\n");
    display(array, n);
    printf("Number of comparisons: %d\n", count);
}

void plotter() {
    srand(time(NULL));
    int *array, n = 10, count;
    FILE *f1, *f2, *f3;
    f1 = fopen("bubbleBest.txt", "a");
    f2 = fopen("bubbleWorst.txt", "a");
    f3 = fopen("bubbleAverage.txt", "a");
    while (n <= 30000) {
        array = (int *)malloc(n * sizeof(int));

        // Best case
        for (int i = 0; i < n; i++)
            array[i] = i + 1;
        count = bubbleSort(array, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst case
        for (int i = 0; i < n; i++)
            array[i] = n - i;
        count = bubbleSort(array, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++)
            array[i] = rand() % n;
        count = bubbleSort(array, n);
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
}

// Driver Code
int main() {
    tester();
    plotter();
    return 0;
}