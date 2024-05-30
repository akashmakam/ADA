// String Matching Algorithm

#include <stdio.h>
#include <string.h>

int stringMatching(char string[], char key[]) {
    int m = strlen(string), n = strlen(key), count = 0;

    for (int i = 0; i <= (m - n); i++) {
        count++;
        int j = 0;
        while ((j < n) && (string[i + j] == key[j])) {
            j++;
            count++;
        }
        if (j == n) {
            break;
        }
    }
    return count;
}

int main() {
    char string[100], key[100];
    int count;
    printf("\nEnter a string: ");
    scanf("%s", string);
    printf("Enter the string to be searched from the above string: ");
    scanf("%s", key);
    count = stringMatching(string, key);
    return 0;
}