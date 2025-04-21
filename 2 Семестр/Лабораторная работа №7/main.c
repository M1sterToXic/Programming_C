#include "student.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    struct Student students[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        char name[64];
        sprintf(name, "Student_%d", i+1);
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;

        students[i] = addStudent(name, math, phy, inf);
    }

    printf("Список студентов ДО сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    sortStudentsByTotal(students, N);

    printf("\nСписок студентов ПОСЛЕ сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    return 0;
}