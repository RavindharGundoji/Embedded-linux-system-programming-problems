#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<pwd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	int status;
	char file_name[20], ower[20];
	printf("Enter file names : ");
	scanf("%s", file_name);
	getchar();
	printf("Enter a owers to change : ");
	scanf("%s", ower);
	getchar();
	struct passwd *pwd = getpwnam(ower);
	if(pwd == NULL){
		printf("%s\n", strerror(errno));
		exit(1);
	}status = chown(file_name, pwd -> pw_uid, -1);
	if(status == -1){
		printf("%s\n", strerror(errno));
		exit(1);
	}printf("ower and group are chnaged successfully\n");
	return 0;
}
