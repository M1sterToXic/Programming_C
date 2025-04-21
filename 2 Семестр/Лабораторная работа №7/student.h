#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5 // Кол-во студентов

struct Student {
    char name[64];
    int math;
    int physics;
    int informatics;
    int total;
};

struct Student addStudent(const char* name, int math, int phy, int inf);
void printStudentInfo(struct Student student);
void sortStudentsByTotal(struct Student students[], int size);

#endif