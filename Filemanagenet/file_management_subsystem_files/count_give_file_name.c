#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(){
	int count = 0;
	DIR *dir;
	struct dirent *entry;
	char path[100], file_name[20];
	printf("Enter a path : ");
	scanf("%s", path);
	getchar();
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	dir = opendir(path);
	while((entry = readdir(dir)) != NULL){
		if(strcmp(entry -> d_name, file_name) == 0){
			count++;
		}
	}closedir(dir);
	printf("Given %s file are presented in dir %d number of times\n", file_name, count);
	return 0;
}
