#include <stdio.h>

int main() {
    // List of file names to clear
    const char* filenames[] = {"e_b.txt", "e_w.txt", "c_b.txt", "c_w.txt", "m_b.txt", "m_w.txt"};

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