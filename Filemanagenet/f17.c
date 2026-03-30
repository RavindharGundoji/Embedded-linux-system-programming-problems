#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  FILE *fp;
  time_t current_time;
  struct tm *time_info;
  char timestr[100];


  // open the log file in append mode

  fp = fopen("log.txt","a");
  if(fp == NULL){
    perror("Error opening log file");
    exit(1);
  }

  // Get current system time
   time(&current_time);  // stores current time in 'current_time'
   time_info = localtime(&current_time); // convert to local time format

   // format time as readable string

   strftime(timestr, sizeof(timestr), "%y-%m-%d %H:%M:%S",time_info);

   // write timestamp to file
   //
  fprintf(fp, "program run at: %s\n",timestr);
  printf("log entry added: %s\n",timestr);

  fclose(fp);
  return 0;
 }
