// Bubble Sort

#include <stdio.h>

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

void selectionSort(int *array, int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min])
                min = j;
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    printf("\nThe sorted elements of the array are:\n");
    display(array, n);
}

// Driver Code
int main() {
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    read(array, n);
    printf("\nThe entered elements of the array are:\n");
    display(array, n);
    selectionSort(array, n);
    return 0;
}