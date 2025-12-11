#include<stdio.h>
#include<unistd.h>

int main() {
   printf("Before fork() \n");

   pid_t pid = fork();  // process creation

   if(pid < 0){
     // Fork failed 

	   printf("Failed to create process. \n");
   }

   else if (pid == 0){
     // child process
     printf("child process : PID = %d , parent PID = %d\n", getpid(), getppid());
   }

     else {
        printf("parent process : PID = %d , child PID = %d\n",getpid(),pid);
     }
   
     printf("This line executes in both processes\n");

     return 0;
 }
