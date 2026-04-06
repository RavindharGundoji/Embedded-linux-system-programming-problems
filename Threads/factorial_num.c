#include <stdio.h>
#include <pthread.h>
void* factorial(void* arg) {
    int n = *(int*)arg;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i)
        fact *= i;
    printf("Factorial of %d = %llu\n", n, fact);
    return NULL;
}
int main() {
    pthread_t tid;
    int num = 5;
    pthread_create(&tid, NULL, factorial, &num);
    pthread_join(tid, NULL);
    return 0;
}

