import java.util.Scanner;

public class quickSortTester {
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

    void quickSort(int[] array, int start, int end) {
        if (start < end) {
            int pivotIndex = partition(array, start, end);
            quickSort(array, start, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, end);
        }
    }

    int partition(int[] array, int start, int end) {
        int pivot = array[end];
        int i = start - 1;

        for (int j = start; j < end; j++) {
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

    public static void main(String[] args) {
        quickSortTester A = new quickSortTester();
        int[] array = A.read();
        int arrayLength = array.length;
        A.quickSort(array, 0, arrayLength - 1);
        A.display(array);
    }
}