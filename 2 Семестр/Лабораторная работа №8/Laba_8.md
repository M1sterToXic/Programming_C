Практическое задание 7. Знакомство с POSIX потоками

Оценка 3. Знакомство с pthread:
1.	Создать поток

Написать программу, которая создает поток с помощью pthread_create(). Использовать атрибуты по умолчанию. Родительский и дочерний потоки должны вывести на экран по 5 строк текста.

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    int choice;
    
    printf("Lab 8: Threads with pthread\n");
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
```

![image](https://github.com/user-attachments/assets/84f3140d-d77c-45bc-b34b-29b43dcaf0fb)


2.	Ожидание потока

Модифицировать упр.1 так, что родительский поток выводит текст после завершения дочернего потока. Подсказка: pthread_join()
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void exercise2() {
    printf("\n=== Exercise 2: Waiting for thread ===\n");
    pthread_t thread;
    pthread_create(&thread, NULL, ex1_thread_func, NULL);
    
    pthread_join(thread, NULL);
    
    for (int i = 0; i < 5; i++) {
        printf("Main thread: line %d\n", i);
    }
}

int main() {
    int choice;
    
    printf("Lab 8: Threads with pthread\n");
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
```

![image](https://github.com/user-attachments/assets/5ec10a18-f488-46e1-b5d0-29a86f702b8a)


3.	Параметры потока

Модифицировать упр.2 так, что основной поток создает 4 потока, исполняющих одну и ту же функцию. Эта функция должна распечатать последовательность текстовых строк, переданных как параметр. Каждый из созданных потоков должен распечатать различные последовательности строк.

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    int choice;
    
    printf("Lab 8: Threads with pthread\n");
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
```

![image](https://github.com/user-attachments/assets/ea5904ba-bcae-469e-a357-ae118fe82f8f)


4.	Завершение нити без ожидания

Добавить сон с помощью sleep() в функцию потоков между выводами строк. Спустя две секунды после создания дочерних потоков основной поток должен прервать работу всех дочерних потоков с помощью pthread_cancel().

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    int choice;
    
    printf("Lab 8: Threads with pthread\n");
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
```

![image](https://github.com/user-attachments/assets/35018906-7157-4c3b-8602-f24fd49da4ed)


5.	Обработать завершение потока

Модифицировать упр. 4 так, чтобы дочерний поток перед завершение распечатывал сообщение об этом. Использовать pthread_cleanup_push()

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void cleanup_handler(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d: cleaning up before termination\n", id);
}

void* ex5_thread_func(void* arg) {
    int id = *(int*)arg;
    
    pthread_cleanup_push(cleanup_handler, arg);
    
    for (int i = 0; i < 5; i++) {
        // This is a cancellation point (sleep)
        printf("Thread %d: line %d\n", id, i);
        sleep(1);
    }

    pthread_cleanup_pop(1);
    
    return NULL;
}

void exercise5() {
    printf("\n=== Exercise 5: Thread cancellation with cleanup ===\n");
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

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    int choice;
    
    printf("Lab 8: Threads with pthread\n");
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
```

![image](https://github.com/user-attachments/assets/dc68ee12-5ced-4357-bd5f-b8e0e3813e54)



6.	Реализовать простой Sleepsort

Реализовать прикольный алгоритм сортировки Sleepsort с асимптотикой O(N) (по времени). Суть алгоритма: на вход подается массив, пусть будет не более 50 элементов и пусть будет состоять из целочисленных значений. Для каждого элемента массива создается отдельный поток, в который в качестве аргумента передается значение элемента. Сам поток должен уйти в сон с помощью sleep() или usleep() с параметром равным аргументу потока (значение элемента массива), а после вывести на экран значение.

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
    
    printf("Lab 8: Threads with pthread\n");
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
```

![image](https://github.com/user-attachments/assets/21a41b19-2d85-4d3c-9c81-504f90f9a8d0)

