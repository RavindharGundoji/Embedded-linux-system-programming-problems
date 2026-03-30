#include<stdio.h>
#include<stdlib.h>

struct student {
  int roll;
  char name[50];
  float marks;
};

int main() {
    FILE *fp;
    struct student s;
    int choice;

    while(1) {
       printf("\n -- student Record system -- \n");
       printf("1. Add Record\n");
       printf("2. Display Records\n");
       printf("3. Exit\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);


       switch(choice){
         case 1:
		 fp = fopen("students.dat","ab"); // append in binary mode
		 if(fp == NULL){
		  perror("Error opening file");
		  return 1;
		 }

		 printf("Enter Roll no: ");
		 scanf("%d",&s.roll);
		 printf("Enter name: ");
		 scanf("%s",s.name);
		 printf("Enter marks: ");
		 scanf("%f",&s.marks);

		 fwrite(&s, sizeof(s),1,fp); // write structure to file
		 fclose(fp);
		 printf("Record added successfully!\n");
		 break;

	 case 2:

	    fp = fopen("students.dat","rb");
           if(fp == NULL) {
	     perror("Error opening file");
	     return 1;
	   }
           
           printf("\n -- student Records -- \n");
           while(fread(&s, sizeof(s), 1, fp)) {
	     printf("Roll: %d | name: %s | marks: %.2f\n",s.roll,s.name,s.marks);
	   }
          fclose(fp);
          break;

        case 3:
          printf("Exiting program...");
          return 0;
        
        default:
           printf("Invalid choice! Try again.\n");	  
       }
     }
    return 0;
}
