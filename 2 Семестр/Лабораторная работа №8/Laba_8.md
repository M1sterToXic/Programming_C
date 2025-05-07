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

7.	Синхронизированный вывод

Модифицируйте программу упр. 5 так, чтобы вывод родительского и дочернего потока был синхронизован: сначала родительский поток выводить первую строку, затем дочерний, затем родительский вторую строку и т.д. Использовать mutex. 

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MAX_SIZE 2500
#define MAX_THREADS 128

// Глобальные переменные для матриц
int N, num_threads;
int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
pthread_mutex_t mutex;

// Структура для передачи данных в поток (упр.7)
typedef struct {
    int id;
    int lines;
} thread_data;

// Структура для передачи данных в поток (упр.8-9)
typedef struct {
    int start_row;
    int end_row;
} thread_mul_data;

// === Упражнение 7: синхронизированный вывод ===

pthread_mutex_t mutex;
pthread_cond_t cond;
int current_turn = 0; // 0 — родитель, 1 — дочерний

void* ex7_thread_func(void* arg) {
    for (int i = 1; i <= 5; i += 2) { 
        pthread_mutex_lock(&mutex);
        while (current_turn != 1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Дочерние потоки: строка %d\n", i);
        sleep(1);
        current_turn = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void exercise7() {
    printf("\n=== Упражнение 7: Синхронизированный вывод родительских/дочерних элементов ===\n");
    pthread_t thread;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread, NULL, ex7_thread_func, NULL);

    for (int i = 0; i <= 5; i += 2) { // Родитель выводит четные строки
        pthread_mutex_lock(&mutex);
        while (current_turn != 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Родительский поток: строка %d\n", i);
        sleep(1);
        current_turn = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}

int main() {
    int choice;
    pthread_mutex_init(&mutex, NULL);

    
    printf("Лабораторная работа: Потоки (упражнения 7-9)\n");
    printf("Выберите упражнение (7-9) или 0 для всех: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 0:
            exercise7();
            exercise8();
            exercise9();
            break;
        case 7:
            exercise7();
            break;
        case 8:
            exercise8();
            break;
        case 9:
            exercise9();
            break;
        default:
            printf("Неверный выбор!\n");
    }
    
    return 0;
}
```

![image](https://github.com/user-attachments/assets/840f989c-1529-4cd0-86d0-3b61fd0c017c)


8.	Перемножение квадратных матриц NxN

a.	Написать функцию произведения двух квадратных матриц A и B размером NxN (на выходе получим матрицу C). Исходные матрицы A и B заполнить единицами в основном потоке с функцией main. Для матриц размером меньше 5 в основном потоке вывести на экран матрицы A, B и C (для проверки правильности работы функции).
b.	С командной строки считать размер матрицы и количество потоков. Распараллелить перемножение матриц разбив матрицу на равные части между потоками в главной функции по следующему принципу: N / threads, например если размер матрицы N = 8, а потоков 4, то каждый из потоков заберет вычисление N/4 = 2 строки и столбца, наглядно:
 
![image](https://github.com/user-attachments/assets/e2d874cb-a91e-491a-908f-879afb8bd211)


c.	Дополнительно (не обязательно) Учесть, что размер матриц может быть не кратен числу потоков, например, N = 18, а число потоков 4, тогда необходимо каждому из потоков выдать по 4x4, а оставшиеся 2x2 досчитать в основном потоке.

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MAX_SIZE 2500
#define MAX_THREADS 128

// Глобальные переменные для матриц
int N, num_threads;
int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
pthread_mutex_t mutex;

// Структура для передачи данных в поток (упр.8-9)
typedef struct {
    int start_row;
    int end_row;
} thread_mul_data;

/* Упражнение 8: Умножение матриц */
void* matrix_multiply(void* arg) {
    thread_mul_data* data = (thread_mul_data*)arg;
    
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

// Инициализация матриц единицами
void initialize_matrices() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }
}

// Вывод матрицы на экран
void print_matrix(int mat[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void exercise8() {
    printf("\n=== Упражнение 8: Умножение матриц ===\n");
    
    // Ввод параметров
    printf("Введите размер матрицы N: ");
    scanf("%d", &N);
    printf("Введите количество потоков: ");
    scanf("%d", &num_threads);
    
    if (N <= 0 || num_threads <= 0) {
        printf("Ошибка: неверные параметры!\n");
        return;
    }
    
    // Инициализация матриц
    initialize_matrices();
    
    pthread_t threads[MAX_THREADS];
    thread_mul_data thread_data[MAX_THREADS];
    
    // Замер времени начала
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    // Распределение работы между потоками
    int rows_per_thread = N / num_threads;
    int extra_rows = N % num_threads;
    int current_row = 0;
    
    // Создание потоков
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start_row = current_row;
        // Добавляем дополнительную строку первым потокам, если нужно
        thread_data[i].end_row = current_row + rows_per_thread + (i < extra_rows ? 1 : 0);
        current_row = thread_data[i].end_row;
        
        pthread_create(&threads[i], NULL, matrix_multiply, &thread_data[i]);
    }
    
    // Ожидание завершения всех потоков
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Замер времени окончания
    gettimeofday(&end, NULL);
    
    // Вычисление времени выполнения в миллисекундах
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000.0 + microseconds / 1000.0;
    
    printf("Время выполнения: %.2f мс\n", elapsed);
    
    // Вывод матриц для маленьких размеров
    if (N < 5) {
        printf("\nМатрица A:\n");
        print_matrix(A);
        
        printf("\nМатрица B:\n");
        print_matrix(B);
        
        printf("\nРезультат (C = A x B):\n");
        print_matrix(C);
    }
}

int main() {
    int choice;
    pthread_mutex_init(&mutex, NULL);

    
    printf("Лабораторная работа: Потоки (упражнения 7-9)\n");
    printf("Выберите упражнение (7-9) или 0 для всех: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 0:
            exercise7();
            exercise8();
            exercise9();
            break;
        case 7:
            exercise7();
            break;
        case 8:
            exercise8();
            break;
        case 9:
            exercise9();
            break;
        default:
            printf("Неверный выбор!\n");
    }
    
    return 0;
}
```

![image](https://github.com/user-attachments/assets/4d98422a-690d-46e7-89b5-c0b3598ef0ef)


9.	Время выполнения

Замерить время выполнения с момента создания потоков (до цикла с pthread_create) и до завершения работы потоков (после цикла pthread_join). Позапускать с разным числом потоков и размером матрицы. Построить график в любой программе (excel, python, matlab и т.д.) или онлайн, который покажет зависимость времени выполнения от размера матрицы и количества потоков. Количество потоков от 1 до 128 с любым разумным шагом. Размер матрицы не более 2500, шаг размера матрицы на свое усмотрение. Пример графика (цветами кол-во потоков, по оси х размер матрицы, по y время в мс):

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MAX_SIZE 2500
#define MAX_THREADS 128

// Глобальные переменные для матриц
int N, num_threads;
int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
pthread_mutex_t mutex;

// Структура для передачи данных в поток (упр.8-9)
typedef struct {
    int start_row;
    int end_row;
} thread_mul_data;

/* Упражнение 9: Анализ производительности */
void exercise9() {
    printf("\n=== Упражнение 9: Анализ производительности ===\n");
    
    // Тестовые размеры матриц и количество потоков
    int sizes[] = {100, 500, 1000, 1500};
    int thread_counts[] = {1, 2, 4, 8, 16, 32, 64, 128};
    int num_sizes = sizeof(sizes)/sizeof(sizes[0]);
    int num_counts = sizeof(thread_counts)/sizeof(thread_counts[0]);
    
    printf("Размер\\Потоки \n");
    for (int t = 0; t < num_counts; t++) {
        printf("\t%d", thread_counts[t]);
    }
    printf("\n");
    
    // Тестирование для каждого размера матрицы
    for (int s = 0; s < num_sizes; s++) {
        N = sizes[s];
        printf("%d", N);
        
        // Инициализация матриц
        initialize_matrices();
        
        // Тестирование для каждого количества потоков
        for (int t = 0; t < num_counts; t++) {
            num_threads = thread_counts[t];
            pthread_t threads[MAX_THREADS];
            thread_mul_data t_data[MAX_THREADS];
            
            struct timeval start, end;
            gettimeofday(&start, NULL);
            
            // Распределение работы
            int rows_per_thread = N / num_threads;
            int extra_rows = N % num_threads;
            int current_row = 0;
            
            // Создание потоков
            for (int i = 0; i < num_threads; i++) {
                t_data[i].start_row = current_row;
                t_data[i].end_row = current_row + rows_per_thread + (i < extra_rows ? 1 : 0);
                current_row = t_data[i].end_row;
                
                pthread_create(&threads[i], NULL, matrix_multiply, &t_data[i]);
            }
            
            // Ожидание завершения
            for (int i = 0; i < num_threads; i++) {
                pthread_join(threads[i], NULL);
            }
            
            gettimeofday(&end, NULL);
            
            // Расчет времени
            long seconds = end.tv_sec - start.tv_sec;
            long microseconds = end.tv_usec - start.tv_usec;
            double elapsed = seconds * 1000.0 + microseconds / 1000.0;
            
            printf("\t%.0f", elapsed);
            fflush(stdout);
        }
        printf("\n");
    }
    
}

int main() {
    int choice;
    pthread_mutex_init(&mutex, NULL);

    
    printf("Лабораторная работа: Потоки (упражнения 7-9)\n");
    printf("Выберите упражнение (7-9) или 0 для всех: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 0:
            exercise7();
            exercise8();
            exercise9();
            break;
        case 7:
            exercise7();
            break;
        case 8:
            exercise8();
            break;
        case 9:
            exercise9();
            break;
        default:
            printf("Неверный выбор!\n");
    }
    
    return 0;
}
```

![image](https://github.com/user-attachments/assets/1f7bae78-ee81-4bc3-8d09-ce7f1f83d303)


![Figure_1](https://github.com/user-attachments/assets/bf97a35a-b3ae-44b6-8606-b2ded32cdd2b)
