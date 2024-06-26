    import java.util.*;
    import java.io.FileWriter;
    import java.io.IOException;

    public class quickSortPlotter {
        int count;

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
                count++;
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
            quickSortPlotter A = new quickSortPlotter();
            Random random = new Random();
            try {
                FileWriter bestCase = new FileWriter("quickBest.txt");
                FileWriter worstCase = new FileWriter("quickWorst.txt");
                FileWriter averageCase = new FileWriter("quickAverage.txt");
                for (int n = 4; n <= 1024; n = n * 2) {
                    int[] array = new int[n];
                
                    // Best case
                    Arrays.fill(array, 1);  // Fill array with 1s
                    A.count = 0;  // Reset count
                    A.quickSort(array, 0, n - 1);  // Correct end index
                    bestCase.write(n + "\t" + A.count + "\n");

                    // Worst case
                    A.count = 0;  // Reset count
                    for (int i = 0; i < n; i++)
                        array[i] = i + 1;
                    A.quickSort(array, 0, n - 1);  // Correct end index
                    worstCase.write(n + "\t" + A.count + "\n");

                    // Average case
                    A.count = 0;  // Reset count
                    for (int i = 0; i < n; i++)
                        array[i] = random.nextInt(n);
                    A.quickSort(array, 0, n - 1);  // Correct end index
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