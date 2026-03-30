#include<stdio.h>

int main() {
  FILE *src , *dest;
  char ch;

  // open source file in read mode
   src = fopen("source.txt","r");
   if(src == NULL) {
     printf("cannot open source file.\n");
     return 1;
   }

   // open destination file in write mode
   dest = fopen("destination.txt","w");
   if(dest == NULL) {
     printf("cannot open destination file.\n");
     fclose(src);
     return 1;
   }

   // Read from source and write to destination
    while((ch = fgetc(src)) != EOF) {
       fputc(ch,dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);

    return 0;
    
}


// optimised version .
/*
 #include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256   // Tunable buffer size depending on RAM

int main() {
    FILE *src = fopen("source.txt", "rb");
    FILE *dest = fopen("destination.txt", "wb");

    if (src == NULL || dest == NULL) {
        perror("File open error");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return EXIT_FAILURE;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Copy in chunks for efficiency
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully (optimized version).\n");

    return EXIT_SUCCESS;
}
 
 */
