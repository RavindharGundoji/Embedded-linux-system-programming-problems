#include<stdio.h>
#include<stdlib.h>

int main() {
 FILE *fp;
 char filename[100];
 long size;

 printf("Enter the filename: ");
 scanf("%s",filename);

 // open the file in read mode
 
 fp = fopen(filename, "r");
 if(fp == NULL){
   perror("Error opening file");
   exit(1);
 }

 // move file pointer to the end of the file
 fseek(fp, 0, SEEK_END);

 // Get the current position of the file pointer (which equals file size)
 size = ftell(fp);

 printf("The size of '%s' is %ld bytes.\n",filename,size);

 fclose(fp);
 return 0;
}
