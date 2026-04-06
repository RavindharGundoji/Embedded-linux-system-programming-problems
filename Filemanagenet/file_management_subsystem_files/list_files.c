#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<errno.h>
int main(){
	DIR *dir;
	struct dirent *entry;
	char str[50];
	printf("Enter a path  : ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	dir = opendir(str);
	if(dir == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}while((entry = readdir(dir)) != NULL){
		printf("%s\n", entry -> d_name);
	}closedir(dir);
	return 0;
}
