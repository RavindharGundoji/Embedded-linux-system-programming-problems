#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* random_numbers(void* arg) {
    srand(time(NULL));
    for (int i = 0; i < 5; ++i)
        printf("Random number: %d\n", rand() % 100);
    return NULL;
}

void* random_string(void* arg) {
    srand(time(NULL));
    char str;
    int n = 10;
    for (int i=0;i<n;i++)
        str[i] = 'a' + rand() % 26;
    str[n] = '\0';
    printf("Random string: %s\n", str);
    return NULL;
}

int main() {
    pthread_t t_num, t_str;
    pthread_create(&t_num, NULL, random_numbers, NULL);
    pthread_create(&t_str, NULL, random_string, NULL);
    pthread_join(t_num, NULL);
    pthread_join(t_str, NULL);
    return 0;
}

