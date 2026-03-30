#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main() {
  char filename[100];
  char line[100];
  int linenumber=1;

  FILE *fp;

  printf("Enter the file name : ");
  scanf("%s",filename);

  fp = fopen(filename,"r");

  if(fp == NULL)
  {
    perror("error");
  }

  while(fgets(line,sizeof(line),fp) != NULL){

     printf("%d : %s",linenumber,line);
     linenumber++;
  }

  fclose(fp);
  return 0;
 }
