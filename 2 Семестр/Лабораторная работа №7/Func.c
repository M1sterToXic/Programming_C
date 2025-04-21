#include "student.h"

struct Student addStudent(const char* name, int math, int phy, int inf) {
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.math = math;
    newStudent.physics = phy;
    newStudent.informatics = inf;
    newStudent.total = math + phy + inf; 
    return newStudent;
}

void printStudentInfo(struct Student student) {
    printf("Имя: %s | Математика: %d | Физика: %d | Информатика: %d | Общий балл: %d\n",
           student.name, student.math, student.physics, student.informatics, student.total);
}

void sortStudentsByTotal(struct Student students[], int size) {
    for(int i = 0; i < size -1; i++) {
        int maxIndex = i;
        for (int j = i+1; j < size; j++) {
            if(students[j].total > students[maxIndex].total) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            struct Student temp = students[i];
            students[i] = students[maxIndex];
            students[maxIndex] = temp;
        }
    }
}