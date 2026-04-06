#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
	char path[150];
	printf("Enter a path of file : ");
	scanf("%s", path);
	struct stat file_stat;
	if(stat(path, &file_stat) == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Ower permissions\n");
	printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	printf("\nGroup permissions\n");
	printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	printf("\nOthar permissions\n");
	printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
	printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	return 0;
}
