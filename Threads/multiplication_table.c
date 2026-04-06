#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct {
    int number;
    int limit;
}table_args;
void *print_table(void *arg){
    table_args *args = (table_args *)arg;
    printf("Multiplication table of %d up to %d:\n", args->number, args->limit);
    for(int i = 1; i <= args->limit; i++){
        printf("%d x %d = %d\n", args->number, i, args->number * i);
    }pthread_exit(NULL);
}
int main(){
    pthread_t tid;
    table_args args;
    printf("Enter a number: ");
    scanf("%d", &args.number);
    printf("Enter limit: ");
    scanf("%d", &args.limit);
    if (pthread_create(&tid, NULL, print_table, &args) != 0) {
        perror("pthread_create failed");
        exit(1);
    }pthread_join(tid, NULL);
    return 0;
}

