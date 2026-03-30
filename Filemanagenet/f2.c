#include<stdio.h>

int main() {
 FILE *inputfile , *outputfile;
 int num , sum = 0;

 // open input file for reading
 
  inputfile = fopen("numbers.txt","r");
  if(inputfile == NULL) {
    printf("Error: cannot open input file.\n");
    return 1;
  }

  // Read integers until end of file

  while(fscanf(inputfile, "%d", &num) == 1) {
     sum += num;
  }

  fclose(inputfile);

  // open output file for writing the sum
  

  outputfile = fopen("sum.txt","w");
  if(outputfile == NULL) {
    printf("Error: cannot open output file. \n");
    return 1;
  }

  fprintf(outputfile, "sum = %d\n",sum);
  fclose(outputfile);

  printf("sum written to sum.txt successfully.\n");
  return 0;
}
