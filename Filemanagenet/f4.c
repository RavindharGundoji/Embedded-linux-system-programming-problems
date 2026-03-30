#include<stdio.h>
#include<stdlib.h>


void createfile() {
  FILE *fp;
  char filename[100], content[1000];

  printf("Enter file name to create: ");
  scanf("%s",filename);
  getchar();

  fp = fopen(filename, "w");
  if(fp == NULL){
    printf("Error creating file!\n");
    return;
  }

  printf("Enter content (end with '~' on new line):\n");
  fgets(content, sizeof(content), stdin);
  fputs(content, fp);

  fclose(fp);
  printf("File created and written successfully. \n");
}


void readfile() {
   FILE *fp; 
   char filename[100],ch;

   printf("Enter file name to read: ");
   scanf("%s",filename);
      

   fp = fopen(filename, "r");
   if(fp == NULL) {
     printf("Error: file not found!\n");
     return;
   }

   printf("\n --- file content -- \n");
   
  

   while((ch = fgetc(fp)) != EOF)
	   printf("%c",ch);
   printf("\n --- ------ \n");

   fclose(fp);
}


void updatefile() {
  FILE *fp;
  char filename[100], content[1000];

  printf("Enter file name to update: ");
  scanf("%s",filename);
  getchar();

  fp = fopen(filename,"a");
  if(fp == NULL){
    printf("Error: file not found!\n");
    return;
  }

  printf("Enter content to append (end with '~' on new line):\n");
  fgets(content, sizeof(content),stdin);
  fputs(content, fp);

  fclose(fp);
  printf("File updated successfully. \n");
}


void deletefile() {
   char filename[100];

   printf("Enter file name to delete: ");
   scanf("%s",filename);

   if(remove(filename) == 0)
	   printf("File deleted successfully.\n");
   else
	   printf("Error deleting the file!\n");
 }

int main() {
  int choice;

  while(1) {
     printf("\n==== File Management System ====\n");
      printf("1. Create and write to a file\n");
        printf("2. Read a file\n");
        printf("3. Update (append) a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
	scanf("%d",&choice);
	getchar();
     
	 switch (choice) {
            case 1: createfile(); break;
            case 2: readfile(); break;
            case 3: updatefile(); break;
            case 4: deletefile(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
	 }
  }

  return 0;
}
