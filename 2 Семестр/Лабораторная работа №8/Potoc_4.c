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