#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main(){
	char path[30], buffer[1024];
	int bytes_read, i;
	FILE *fp;
	printf("Enter a path : ");
	scanf("%s", path);
	getchar();
	fp = fopen(path, "rb");
	if(fp == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("-------------------Contents of file---------------\n");
	while((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0){
		for(i = 0; i < bytes_read; i++){
			printf("%02x ",buffer[i]);
		}printf("\n");
	}printf("--------------- ---Data as printed-----------------\n");
	fclose(fp);
	return 0;
}
