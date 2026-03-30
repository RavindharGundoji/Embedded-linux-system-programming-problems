#include<stdio.h>
#include<stdlib.h>
int main(void){
 FILE *fp;
 char str[100];

 fp = fopen("text.txt","w");

 if(fp == NULL){
   printf("Error occured while opening a file \n");
   exit(1);
 }

 printf("Enter the text \n");
 printf("To stope entering press cntrl+z\n");
 while(fgets(str, sizeof(str),stdin) != NULL)
 {
   fputs(str,fp);
 }

 fclose(fp);
 printf("\ndata is  successfully written to text.txt file \n");
 return 0;
}
