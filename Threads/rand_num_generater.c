#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* generate_random_numbers(void* arg) {
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        int r = rand() % 100;
        printf("Random number: %d\n", r);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, generate_random_numbers, NULL);
    pthread_join(tid, NULL);
    return 0;
}

