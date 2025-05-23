#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N 1000000

struct Student {
    char name[64];  // Используем массив символов для хранения имени
    int math;
    int physics;    // Оценка
    int informatics;
    int total;
};

struct Student addStudent(const char* name, int math, int phy, int inf) {
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}



void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Student students[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&students[randomIndex], &students[high]);

    int pivot = students[high].total; // Опорный элемент (последний элемент)
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (students[j].total <= pivot) {
            i++;
            swap(&students[i], &students[j]);
        }
    }
    swap(&students[i + 1], &students[high]);
    return i + 1;
}

void Quick_Sort(struct Student students[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pi = partition(students, low, high);
    Quick_Sort(students, low, pi - 1);
    Quick_Sort(students, pi + 1, high);
}

void printStudentInfo(struct Student student) {
    printf("Имя: %s | Математика: %d | Физика: %d | Информатика: %d | Общий балл: %d\n",
           student.name, student.math, student.physics, student.informatics, student.total);
}



// Функция для замера времени выполнения сортировки
void measureSortingTime(struct Student students[], int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Засекаем начальное время
    Quick_Sort(students, 0, size - 1); // Выполняем сортировку
    end = clock(); // Засекаем конечное время

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения сортировки: %f секунд\n", cpu_time_used);
}

void printDataSize(int size) {
    size_t dataSize = size * sizeof(struct Student);
    printf("Размер данных: %zu байт\n", dataSize);
}

int main() {
    struct Student students[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        char name[64];
        sprintf(name, "Student_%d", i + 1);
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;

        students[i] = addStudent(name, math, phy, inf);
    }

    printf("Вывод списка ДО сортировки:\n");
    // for (int i = 0; i < N; i++) {
    //     printStudentInfo(students[i]);
    // }

    Quick_Sort(students, 0, N -1);

    // printf("\nВывод списка ПОСЛЕ сортировки:\n");
    // for (int i = 0; i < N; i++) {
    //     printStudentInfo(students[i]);
    // }

    // Замер времени выполнения сортировки
    printf("\nЗамер времени для Quick Sort:\n");
    measureSortingTime(students, N);
    printDataSize(N);


    return 0;
}
