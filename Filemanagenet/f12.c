#include<stdio.h>

int main() {

	int n, num;
	FILE *fp;

  fp = fopen("data.bin","wb");
  if(fp == NULL){
     perror("Error creating file");
     return 1;
  }

  printf("Enter how many integers: ");
  scanf("%d",&n);

  printf("Enter %d integers:\n",n);
  for(int i = 0;i < n; i++) {
   scanf("%d",&num);
   fwrite(&num, sizeof(int),1,fp);
  }
  fclose(fp);
  printf("Binary file created successfully!\n");

  return 0;
}
