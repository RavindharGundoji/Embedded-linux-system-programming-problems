#include <stdio.h>
#include <pthread.h>

void* sum_of_two(void* arg) {
    int* nums = (int*)arg;
    printf("Sum of %d and %d = %d\n", nums[0], nums[1], nums[0] + nums[1]);
    return NULL;
}

void* sum_of_squares(void* arg) {
    int n = *(int*)arg;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += i * i;
    printf("Sum of squares 1 to %d = %d\n", n, sum);
    return NULL;
}

void* sum_even_numbers(void* arg) {
    int limit = *(int*)arg;
    int sum = 0;
    for(int i=2; i <= limit; i+=2)
        sum += i;
    printf("Sum of even numbers up to %d = %d\n", limit, sum);
    return NULL;
}

void* average_array(void* arg) {
    int* arr = (int*)arg;
    int n = 5;
    int sum = 0;
    for(int i=0; i<n; ++i)
        sum += arr[i];
    printf("Average of array = %.2f\n", sum/(float)n);
    return NULL;
}

void* product_range(void* arg) {
    int n = *(int*)arg;
    int prod = 1;
    for (int i = 1; i <= n; ++i)
        prod *= i;
    printf("Product of numbers 1 to %d = %d\n", n, prod);
    return NULL;
}

int main() {
    pthread_t tid1, tid2, tid3, tid4, tid5;
    
    int nums[2] = {3, 7};
    int limit = 10;
    int arr[5] = {1, 2, 3, 4, 5};
    
    pthread_create(&tid1, NULL, sum_of_two, nums);
    pthread_create(&tid2, NULL, sum_of_squares, &limit);
    pthread_create(&tid3, NULL, sum_even_numbers, &limit);
    pthread_create(&tid4, NULL, average_array, arr);
    pthread_create(&tid5, NULL, product_range, &limit);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);

    return 0;
}

