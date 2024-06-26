import java.util.*;
import java.io.FileWriter;
import java.io.IOException;

class mergeSortPlotter {
    int count;
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
    
    void worstCaseArrayGenerator(int[] array) {
        int arrayLength = array.length;
        if (arrayLength <= 1)
            return;
        else {
            int middle = arrayLength/2;
            int[] leftArray = new int[middle];
            int[] rightArray = new int[arrayLength - middle];

            for (int i = 0; i < middle; i++)
                    leftArray[i] = array[2*i];
            for (int j = 0; j < (arrayLength - middle); j++)
                    rightArray[j] = array[(2*j)+1];

            worstCaseArrayGenerator(leftArray);
            worstCaseArrayGenerator(rightArray);
   
            int i;
            for (i = 0; i < middle; i++)
                array[i] = leftArray[i];
            for (int j = 0; j < (arrayLength - middle); j++)
                array[j + i] = rightArray[j];
        }
    }
    public static void main(String[] args) {
        mergeSortPlotter A = new mergeSortPlotter();
        Random random = new Random();
        try {
            FileWriter bestCase = new FileWriter("mergeBest.txt");
            FileWriter worstCase = new FileWriter("mergeWorst.txt");
            FileWriter averageCase = new FileWriter("mergeAverage.txt");
            for (int n = 2; n <= 1024; n = n * 2) {
                int[] array = new int[n]; 
               
                // Best case
                A.count = 0;
                for (int i = 0; i < n; i++)
                    array[i] = i+1;
                A.mergeSort(array);
                bestCase.write(n + "\t" + A.count + "\n");

                // Worst case
                A.count = 0;
                A.worstCaseArrayGenerator(array);
                A.mergeSort(array);
                worstCase.write(n + "\t" + A.count + "\n");

                // Average case
                A.count = 0;
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