#include<stdio.h>
#include<stdlib.h>


int main() {

  FILE *src, *dest;
  char sourcefile[100], destfile[100];
  unsigned char buffer;

  printf("Enter source binary file name: ");
  scanf("%s", sourcefile);

  printf("Enter destination file name: ");
  scanf("%s", destfile);

  src = fopen(sourcefile, "rb");
  if(src == NULL){
    perror("Error opening source file");
    exit(1);
  }

  dest = fopen(destfile, "wb");
  if(dest == NULL) {
    perror ("Error opening destination file");
    fclose(src);
    exit(1);
  }

  while(fread(&buffer, sizeof(unsigned char), 1,src) == 1){
       fwrite(&buffer, sizeof(unsigned char), 1, dest);
  }

  printf("File copied successfully!\n");

  fclose(src);
  fclose(dest);

  return 0 ;
}
