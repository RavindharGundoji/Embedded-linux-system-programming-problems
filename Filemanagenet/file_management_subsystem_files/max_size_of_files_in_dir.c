#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
int main(){
	long long int max_size = -1;
	char path[256], larger_file[256];
	DIR *dir;
	struct dirent *entry;
	struct stat file_stat;
	printf("Enter a path : ");
	scanf("%s", path);
	getchar();
	dir = opendir(path);
	if(dir == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}while((entry = readdir(dir)) != NULL){
		char full_path[512];
		if(((strcmp(entry -> d_name, ".")) == 0) || (strcmp(entry -> d_name, "..")) == 0){
			continue;
		}snprintf(full_path, sizeof(full_path), "%s/%s", path, entry -> d_name);
		if((stat(full_path, &file_stat)) == -1){
			printf("%s\n", strerror(errno));
			continue;
		}if(S_ISREG(file_stat.st_mode)){
			if(file_stat.st_size > max_size){
				max_size = file_stat.st_size;
				strncpy(larger_file, full_path, sizeof(larger_file));
			}
		}
	}if(max_size == -1){
		printf("No regular file is found\n");
	}else{
		larger_file[sizeof(larger_file)-1] = '\0';
		printf("Larger file name : %s\n", larger_file);
		printf("Size of larger file : %lld\n", max_size);
	}return 0;
}
