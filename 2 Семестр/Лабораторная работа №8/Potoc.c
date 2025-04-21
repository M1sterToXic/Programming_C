#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Функции для каждого упражнения
void* ex1_thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Child thread: line %d\n", i);
    }
    return NULL;
}

void exercise1() {
    printf("=== Exercise 1: Creating a thread ===\n");
    pthread_t thread;
    pthread_create(&thread, NULL, ex1_thread_func, NULL);
    
    for (int i = 0; i < 5; i++) {
        printf("Main thread: line %d\n", i);
    }
    
    pthread_join(thread, NULL);
}

void exercise2() {
    printf("\n=== Exercise 2: Waiting for thread ===\n");
    pthread_t thread;
    pthread_create(&thread, NULL, ex1_thread_func, NULL);
    
    pthread_join(thread, NULL);
    
    for (int i = 0; i < 5; i++) {
        printf("Main thread: line %d\n", i);
    }
}

void* ex3_thread_func(void* arg) {
    char* msg = (char*)arg;
    for (int i = 0; i < 5; i++) {
        printf("Thread %s: line %d\n", msg, i);
    }
    return NULL;
}

void exercise3() {
    printf("\n=== Exercise 3: Thread parameters ===\n");
    pthread_t threads[4];
    char* messages[] = {"A", "B", "C", "D"};
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, ex3_thread_func, messages[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
}

void* ex4_thread_func(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 5; i++) {
        printf("Thread %d: line %d\n", id, i);
        sleep(1);
    }
    return NULL;
}

void exercise4() {
    printf("\n=== Exercise 4: Thread cancellation ===\n");
    pthread_t threads[4];
    int ids[] = {1, 2, 3, 4};
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, ex4_thread_func, &ids[i]);
    }
    
    sleep(2);
    
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }
    
    printf("Main thread: all child threads canceled\n");
}

void ex5_cleanup_handler(void* arg) {
    printf("Cleanup handler: Thread %d is being canceled\n", *(int*)arg);
}

void* ex5_thread_func(void* arg) {
    int id = *(int*)arg;
    pthread_cleanup_push(ex5_cleanup_handler, arg);
    
    for (int i = 0; i < 5; i++) {
        printf("Thread %d: line %d\n", id, i);
        sleep(1);
    }
    
    pthread_cleanup_pop(0);
    return NULL;
}

void exercise5() {
    printf("\n=== Exercise 5: Cleanup handlers ===\n");
    pthread_t threads[4];
    int ids[] = {1, 2, 3, 4};
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, ex5_thread_func, &ids[i]);
    }
    
    sleep(2);
    
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }
    
    printf("Main thread: all child threads canceled\n");
}

void* sleep_sort(void* arg) {
    int value = *(int*)arg;
    sleep(value);
    printf("%d ", value);
    return NULL;
}

void exercise6() {
    printf("\n=== Exercise 6: Sleepsort ===\n");
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    pthread_t threads[n];
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, sleep_sort, &arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
}

int main() {
    int choice;
    
    printf("Lab 7: Threads with pthread\n");
    printf("Choose exercise (1-6) or 0 to run all: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 0:
            exercise1();
            exercise2();
            exercise3();
            exercise4();
            exercise5();
            exercise6();
            break;
        case 1:
            exercise1();
            break;
        case 2:
            exercise2();
            break;
        case 3:
            exercise3();
            break;
        case 4:
            exercise4();
            break;
        case 5:
            exercise5();
            break;
        case 6:
            exercise6();
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}