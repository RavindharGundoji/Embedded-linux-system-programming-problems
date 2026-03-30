#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(){
  FILE *fp;
  char old[100],newname[100];

  printf("Enter filename : ");
  scanf("%s",old);

  printf("\nEnter newname of file :");
  scanf("%s",newname);

  if(rename(old,newname) == 0){
    printf("File %s is renamed to %s",old,newname);
  }
  else{
    perror("error");
  }

  return 0;
}
