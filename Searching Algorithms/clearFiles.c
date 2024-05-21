#include <stdio.h>

int main() {
    // List of file names to clear
    const char* filenames[] = {"linearbest.txt", "linearworst.txt", "linearavg.txt", "binarybest.txt", "binaryavg.txt", "binaryworst.txt"};

    // Loop through each file name
    for (int i = 0; i < (int)(sizeof(filenames) / sizeof(filenames[0])); i++) {
        FILE* file = fopen(filenames[i], "w"); // Open file in write mode (clears existing content)
        
        // Check if file opened successfully
        if (file == NULL) {
            printf("Failed to open %s\n", filenames[i]);
        } else {
            printf("Cleared contents of %s\n", filenames[i]);
            fclose(file); // Close the file
        }
    }

    return 0;
}