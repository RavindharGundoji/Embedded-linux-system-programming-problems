#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int fd, ret, i , new_line = 0, line[30];
	char str[1024], given_str[1024], file_name[30];
	printf("Enter a file name : ");
	scanf("%s", file_name);
	getchar();
	printf("Enter the string to search : ");
	scanf("%s", given_str);
	fd = open(file_name, O_RDONLY);
	if(fd == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}while((ret = read(fd, str, sizeof(str))) > 0){
		str[ret] = '\0';
		new_line++;
		if(new_line == 10){
			break;
		}
	}printf("10 lines are printed from file\n");
	close(fd);
	return 0;
}
