#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  FILE *fp;
  char filename[100];
  char search[50];
  char line[200];
  int linenumber = 0;
  int found = 0;

  printf("Enter the filename: ");
  scanf("%s", filename);

  printf("Enter the word/string to search: ");
  scanf("%s",search);

  fp = fopen(filename, "r");
  if(fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read file line by line 
   while(fgets(line, sizeof(line), fp) != NULL){
     linenumber++;

     if(strstr(line,search) != NULL) {
        printf("Found '%s' in line %d: %s", search, linenumber, line);
	found = 1;
     }
   }

   if(!found)
	   printf("'%s' not found in the file.\n",search);

   fclose(fp);
   return 0;
}
