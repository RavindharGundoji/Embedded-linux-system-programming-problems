#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	int ret;
	char comment[256];
	fp = fopen("./input_files/instructions.txt", "r");
	if(fp == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}while(fgets(comment, sizeof(comment), fp) != NULL){
		comment[strcspn(comment, "\n")] = '\0';
		if(strlen(comment) == 0){
			continue;
		}printf("Executeing : %s\n", comment);
		ret = system(comment);
		if(ret == -1){
			printf("%s\n", strerror(errno));
			continue;
		}
	}fclose(fp);
	return 0;
}
