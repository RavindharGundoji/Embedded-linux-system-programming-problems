#include<stdio.h>
#include<stdlib.h>

int main() {
  FILE *fp;
  char filename[100];
  int n;
  long pos;
  int count = 0;
  char ch;

  printf("Enter filename: ");
  scanf("%s", filename);

  printf("Enter number of lines to display from the end: ");
  scanf("%d",&n);

  fp = fopen(filename, "r");
  if(fp == NULL){
    perror("Error opening file");
    exit(1);
  }

  // move pointer to end of file
  fseek(fp, 0, SEEK_END);
  pos = ftell(fp); // current position = end of file

 // Go backward to find n newline characters
  while(pos > 0 && count <= n){
    fseek(fp, --pos, SEEK_SET); // move one character back
    ch = fgetc(fp);
    if(ch == '\n')
	    count++;
  }

  // If we reached the beginning before finding n lines , move to start
  
  if(pos != 0)
	  fseek(fp,++pos, SEEK_SET);
  else
	  fseek(fp, 0, SEEK_SET);

  printf("\n --- last %d lines --- \n",n);

  // printf the remaining part of the file

  while((ch = fgetc(fp)) != EOF)
	  putchar(ch);

  fclose(fp);
  return 0;
}
