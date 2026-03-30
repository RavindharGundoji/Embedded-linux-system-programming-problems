#include<stdio.h>
#include<stdlib.h>

int main() {
  FILE *fp;
  char filename[100];

  printf("\nEnter the filename : ");
  scanf("%s",filename);

  fp = fopen(filename,"r");

  if(fp == NULL){
     printf("\nFile does not exists.. ");
  }else{
   printf("\nFile %s exists ", filename);
   fclose(fp);
  }
  return 0;

}
