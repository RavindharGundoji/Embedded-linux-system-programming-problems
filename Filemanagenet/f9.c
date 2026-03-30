#include<stdio.h>

int main() {
 FILE *fp;
 FILE *temp;

 char filename[100];
 char tempfile[] = "temp.txt";
 char ch ;

 int linenum , currentline=1;

 printf("enter file name : ");
 scanf("%s\n",filename);

 printf("enter line number to delete: ");
 scanf("%d",&linenum);

 fp = fopen(filename,"r");
 temp = fopen(tempfile,"w");

 if(!fp || !temp){
     perror("error");
     return 1;
 }

 // delete specific line character by character
 
 while((ch = fgetc(fp)) != EOF){
      if(currentline != linenum)
	      fputc(ch, temp);
      if(ch == '\n')
	      currentline++;
 }

 fclose(fp);
 fclose(temp);
 remove(filename);
 rename(tempfile, filename);

 printf("Line %d deleted successfully.\n",linenum);
 return 0;
 
}
