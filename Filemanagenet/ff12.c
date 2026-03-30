#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main() {
  FILE *fp;
  char filename[100];
  int num;
  int max = INT_MIN;
  int min = INT_MAX;

  printf("Enter the binary file name: ");
  scanf("%s",filename);

  fp = fopen(filename, "rb");
  if(fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read integers one by one from the file

  while(fread(&num, sizeof(int), 1,fp) == 1){
     if(num > max)
	     max = num;
     if(num < min)
	     min = num;
  }

  fclose(fp);

  printf("Maximum value = %d\n", max);
  printf("Minimum value = %d\n", min);

  return 0;
}
