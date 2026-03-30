#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100];
    int ch;
    int inword = 0;
    int wordcount = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read character by character
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch)) {
            inword = 0;
        } else if (inword == 0) {
            inword = 1;
            wordcount++;
        }
    }

    fclose(fp);
    printf("Total number of words: %d\n", wordcount);

    return 0;
}

