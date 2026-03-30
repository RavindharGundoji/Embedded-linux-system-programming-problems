#include<stdio.h>
#include<stdlib.h>

int main() {
  char filename[100];
  char content[100];

  printf("Enter file name : ");
  scanf("%s",filename);

  FILE *fp;

  fp = fopen(filename,"a");

  if(fp == NULL){
    perror("Error while opening file.\n");
    exit(1);
  }

  getchar();  // clear input buffer before taking string input.

  printf("Enter text to append :");
  fgets(content , sizeof(content),stdin);

  fputs(content,fp);

  fclose(fp);

  printf("Data is successfully appended to %s\n",filename);

  return 0;
 }
