#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
void *thread_fun(void *str){
	char *str1 = (char*)str;
	int i = 0;
	int j = strlen(str1)-1;
	int *is_pal = malloc(sizeof(int));
	*is_pal = 1;
	while(i < j){
		if(str1[i] != str1[j]){
			*is_pal = 0;
			break;
		}*is_pal = 1;
		i++;
		j--;
	}return (void*)is_pal;
}int main(){
	char str[30];
	void *ret_val;
	int result;
	printf("Enter a string : ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	pthread_t ti;
	pthread_create(&ti, NULL, thread_fun, str);
	pthread_join(ti, &ret_val);
	result = *(int*)ret_val;
	free(ret_val);
	if(result){
		printf("Given string is palindrome\n");
	}else{
		printf("Given string is not palindrome\n");
	}return 0;
}
