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

void merge(int *leftArray, int leftSize, int *rightArray, int rightSize, int *array) {
    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        count++;
        if (leftArray[l] < rightArray[r]) {
            array[i++] = leftArray[l++];
        } else {
            array[i++] = rightArray[r++];
        }
    }

    while (l < leftSize) {
        array[i++] = leftArray[l++];
    }

    while (r < rightSize) {
        array[i++] = rightArray[r++];
    }
}

void worstCaseArrayGenerator(int *array, int n) {
    if (n <= 1) {
        return;
    }

    int middle = n / 2;
    int *leftArray = (int *)malloc(middle * sizeof(int));
    int *rightArray = (int *)malloc((n - middle) * sizeof(int));

    for (int i = 0; i < middle; i++) {
        leftArray[i] = array[2 * i];
    }
    for (int j = 0; j < (n - middle); j++) {
        rightArray[j] = array[(2 * j) + 1];
    }

    worstCaseArrayGenerator(leftArray, middle);
    worstCaseArrayGenerator(rightArray, n - middle);

    for (int i = 0; i < middle; i++) {
        array[i] = leftArray[i];
    }
    for (int j = 0; j < (n - middle); j++) {
        array[j + middle] = rightArray[j];
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int *array, int n) {
    if (n <= 1) {
        return;
    } else {
        int middle = n / 2;
        int *leftArray = (int *)malloc(middle * sizeof(int));
        int *rightArray = (int *)malloc((n - middle) * sizeof(int));

        for (int i = 0; i < n; i++) {
            if (i < middle)
                leftArray[i] = array[i];
            else
                rightArray[i - middle] = array[i];
        }

        mergeSort(leftArray, middle);
        mergeSort(rightArray, n - middle);
        merge(leftArray, middle, rightArray, n - middle, array);

        free(leftArray);
        free(rightArray);
    }
}

int main() {
    int n;
    int *array = read(&n);
    mergeSort(array, n);
    display(array, n);
    printf("\nThis took %d comparisons.\n", count);
    free(array);
    return 0;
}