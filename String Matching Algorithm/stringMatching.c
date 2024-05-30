// String Matching Algorithm

#include <stdio.h>
#include <string.h>

void stringMatching(char string[], char key[]) {
    int m = strlen(string), n = strlen(key), count = 0;
    int found = 0;

    for (int i = 0; i <= (m - n); i++) {
        count++;
        int j = 0;
        while ((j < n) && (string[i + j] == key[j])) {
            j++;
            count++;
        }
        if (j == n) {
            printf("%s is present in %s! This took %d comparisions.\n", key, string, count);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%s is not present in %s! This took %d comparisions.\n", key, string, count);
    }
}

int main() {
    char string[100], key[100];
    printf("\nEnter a string: ");
    scanf("%s", string);
    printf("Enter the string to be searched from the above string: ");
    scanf("%s", key);
    stringMatching(string, key);
    return 0;
}