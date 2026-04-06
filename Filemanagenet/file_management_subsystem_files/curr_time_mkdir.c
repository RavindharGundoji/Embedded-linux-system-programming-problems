#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<time.h> 
int main(){
	char path[30];
	printf("Enter a path : ");
	scanf("%s", path);
	getchar();
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);
	if(!tm_info){
		printf("%s\n", strerror(errno));
		exit(1);
	}if(strftime(path, sizeof(path), "%y-%m-%d", tm_info) == 0){
		printf("%s\n", strerror(errno));
		exit(1);
	}if((mkdir(path, 0755)) == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("Directory created successfully!\n");
	return 0;
}
