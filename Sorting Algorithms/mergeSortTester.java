import java.util.*;

class tester {
    int count = 0;
    int[] read() {
        Scanner in = new Scanner(System.in);
        System.out.print("\nEnter the size of the array: ");
        int arrayLength = in.nextInt();
        int[] array = new int[arrayLength];
        System.out.println("\nEnter the elements of the array:");
        for (int i = 0; i < arrayLength; i++)
            array[i] = in.nextInt();
        return array;
    }

    void display(int[] array) {
        int arrayLength = array.length;
        System.out.println("\nThe sorted array is:");
        for (int i = 0; i < arrayLength; i++)
            System.out.print(array[i] + "\t");
    }

    void merge(int[] leftArray, int[] rightArray, int[] array) {
        int leftSize = leftArray.length;
        int rightSize = rightArray.length;

        int i, l, r;
        i = l = r = 0;

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

    void mergeSort(int[] array) {
        int arrayLength = array.length;
        if (arrayLength <= 1)
            return;
        else {
            int middle = arrayLength/2;
            int[] leftArray = new int[middle];
            int[] rightArray = new int[arrayLength - middle];

            int j = 0;

            for (int i = 0; i < arrayLength; i++) {
                if (i < middle) {
                    leftArray[i] = array[i];
                } else {
                    rightArray[j++] = array[i];
                }
            }

            mergeSort(leftArray);
            mergeSort(rightArray);
            merge(leftArray, rightArray, array);
        }
    }
}

class mergeSortTester {
    public static void main(String[] args) {
        tester A = new tester();
        int[] array = A.read();
        A.mergeSort(array);
        A.display(array);
        System.out.println("\n" + A.count);
    }
}