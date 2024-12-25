#include <stdio.h>

int main() {
    FILE *fptr;

    // Open a file in write mode
    fptr = fopen("example.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write to the file
    fprintf(fptr, "Hello, World!\n");

    // Close the file
    fclose(fptr);

    return 0;
}
