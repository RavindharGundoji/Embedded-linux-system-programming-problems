#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
void *check_perfect_square(void *arg) {
    int num = *((int *)arg);
    int sqrt_num = (int)sqrt(num);
    if(sqrt_num * sqrt_num == num){
        printf("%d is a perfect square\n", num);
    }else{
        printf("%d is NOT a perfect square\n", num);
    }pthread_exit(NULL);
}
int main() {
    int number;
    pthread_t tid;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (pthread_create(&tid, NULL, check_perfect_square, &number) != 0) {
        perror("pthread_create failed");
        exit(1);
    }pthread_join(tid, NULL);
    return 0;
}

