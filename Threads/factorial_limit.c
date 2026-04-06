#include <stdio.h>
#include <pthread.h>
void* fibonacci_sum(void* arg) {
    int n = *(int*)arg, a = 0, b = 1, sum = 0, temp;
    for (int i = 0; i < n; ++i) {
        sum += a;
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("Sum of first %d Fibonacci numbers = %d\n", n, sum);
    return NULL;
}
int main() {
    pthread_t tid;
    int limit = 10;
    pthread_create(&tid, NULL, fibonacci_sum, &limit);
    pthread_join(tid, NULL);
    return 0;
}

