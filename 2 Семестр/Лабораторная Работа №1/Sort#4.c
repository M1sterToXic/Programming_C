#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N 1000 // Количество студентов

// Определение структуры Student
struct Student {
    char name[64];  
    int math;       
    int physics;    
    int informatics;
    int total;      
};

// Функция создания и инициализации структуры Student
struct Student addStudent(const char* name, int math, int phy, int inf) {
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

// Функция вывода информации о студенте
void printStudentInfo(struct Student student) {
    printf("Имя: %s | Математика: %d | Физика: %d | Информатика: %d | Общий балл: %d\n",
           student.name, student.math, student.physics, student.informatics, student.total);
}

// Функция поиска максимального значения общего балла
int getMaxTotal(struct Student students[], int size) {
    int max = students[0].total;
    for (int i = 1; i < size; i++) {
        if (students[i].total > max) {
            max = students[i].total;
        }
    }
    return max;
}

// Функция сортировки подсчетом для конкретного разряда (по убыванию)
void countingSort(struct Student students[], int size, int exp) {
    struct Student output[size]; // Временный массив для сортировки
    int count[10] = {0}; // Массив для подсчета цифр (0-9)

    // Подсчет количества элементов по текущему разряду
    for (int i = 0; i < size; i++) {
        int digit = (students[i].total / exp) % 10;
        count[digit]++;
    }

    // Изменяем count[i], чтобы получить правильные позиции в output[]
    for (int i = 8; i >= 0; i--) {
        count[i] += count[i + 1]; // Изменено для убывания
    }

    // Заполняем выходной массив, начиная с конца (сортировка по убыванию)
    for (int i = size - 1; i >= 0; i--) {
        int digit = (students[i].total / exp) % 10;
        output[count[digit] - 1] = students[i];
        count[digit]--;
    }

    // Копируем отсортированные элементы обратно в исходный массив
    for (int i = 0; i < size; i++) {
        students[i] = output[i];
    }
}

// Функция Radix Sort (по убыванию)
void radixSort(struct Student students[], int size) {
    int max = getMaxTotal(students, size);

    // Выполняем сортировку подсчетом для каждого разряда (единицы, десятки, сотни и т. д.)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(students, size, exp);
    }
}

// Функция вывода информации о процессоре (Linux)
void printCPUInfo() {
    printf("Информация о процессоре:\n");
    system("cat /proc/cpuinfo | grep 'model name' | uniq");
    system("cat /proc/cpuinfo | grep 'cpu MHz' | uniq");
}

// Функция для измерения времени выполнения сортировки
void measureSortingTime(struct Student students[], int size) {
    clock_t start = clock();
    radixSort(students, size);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Время сортировки: %.6f секунд\n", time_spent);
}

// Функция вывода размера массива студентов в памяти
void printDataSize(int size) {
    printf("Размер данных: %lu байт\n", size * sizeof(struct Student));
}

// Главная функция
int main() {
    struct Student students[N]; 
    srand(time(NULL));

    // Заполняем массив случайными данными
    for (int i = 0; i < N; i++) {
        char name[64];
        sprintf(name, "Student_%d", i + 1);
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;

        students[i] = addStudent(name, math, phy, inf);
    }

    // Замер времени выполнения Radix Sort
    printf("\nЗамер времени для Radix Sort (по убыванию):\n");
    measureSortingTime(students, N);
    printDataSize(N);

    // Вывод списка студентов после сортировки
    printf("\nСписок студентов ПОСЛЕ сортировки (по убыванию):\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    // Вывод информации о процессоре
    printCPUInfo();

    return 0;
}


