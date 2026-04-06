#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
int main(){
	char path[256];
	printf("Enter a path : ");
	scanf("%s", path);
	getchar();
	if(access(path, R_OK) == 0){
		printf("Given file can be readable\n");
	}else{
		printf("Given file can't be readable\n");
	}return 0;
}
