#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i) {
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    selectionSort(array, n);
    printf("\nThe array after sorting is as follows:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
    return 0;
}