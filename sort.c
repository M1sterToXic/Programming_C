//comment 2
//comment
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N 5 // Кол-во студентов

struct Student {
    char name[64];  // Используем массив символов для хранения имени
    int math;
    int physics;    // Оценка
    int informatics;
    int total;
};

struct Student addStudent(const char* name, int math, int phy, int inf){
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.total = math + phy + inf; 
    return newStudent;
}

void printStudentInfo(struct Student student){
    printf("Имя: %s | Математика: %d | Физика: %d | Информатика: %d | Общий балл: %d\n",
           student.name, student.math, student.physics, student.informatics, student.total);
}

//Сортировка
void sortStudentsByTotal(struct Student students[], int size){
    for(int i = 0; i <size -1; i++){
        int maxIndex = i;
        for (int j = i+1; j < size; j++){
            if(students[j].total > students[maxIndex].total) {
                maxIndex = j;
            }
        }
        //Обмен элементов
        if (maxIndex != i){
            struct Student temp = students[i];
            students[i] = students[maxIndex];
            students[maxIndex] = temp;
        }
    }
}

int main(){
    struct Student students[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++){
        char name[64];
        sprintf(name, "Student_%d", i+1);
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;

        students[i] = addStudent(name, math, phy, inf);
    }

     // Вывод списка до сортировки
    printf("Список студентов ДО сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    // Сортируем студентов по убыванию общего балла
    sortStudentsByTotal(students, N);

    // Вывод списка после сортировки
    printf("\nСписок студентов ПОСЛЕ сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    return 0;
}
