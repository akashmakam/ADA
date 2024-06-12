import java.util.*;
import java.io.FileWriter;
import java.io.IOException;

class plotter {
    int count = 0;

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

class mergeSortPlotter {
    public static void main(String[] args) {
        plotter B = new plotter();
        plotter W = new plotter();
        plotter A = new plotter();
        Random random = new Random();
        try {
            FileWriter bestCase = new FileWriter("mergeBest.txt");
            FileWriter worstCase = new FileWriter("mergeWorst.txt");
            FileWriter averageCase = new FileWriter("mergeAverage.txt");
            for (int n = 2; n <= 1024; n = n * 2) {
                int[] array = new int[n];
                
                // Best case
                for (int i = 0; i < n; i++)
                    array[i] = i+1;
                B.mergeSort(array);
                bestCase.write(n + "\t" + B.count + "\n");

                // Worst case
                for (int i = 0; i < n; i++)
                    array[i] = n-i;
                W.mergeSort(array);
                worstCase.write(n + "\t" + W.count + "\n");

                // Average case
                for (int i = 0; i < n; i++)
                    array[i] = random.nextInt(1024);
                A.mergeSort(array);
                averageCase.write(n + "\t" + A.count + "\n");
                
            }
            bestCase.close();
            worstCase.close();
            averageCase.close();
        } catch (IOException e) {
            System.out.println("An error has occurred.");
            e.printStackTrace();
        }
    }
}
