#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N 1000 

struct Student {
    char name[64];  
    int math;       
    int physics;    
    int informatics;
    int total;      
};

struct Student addStudent(const char* name, int math, int phy, int inf);
void printStudentInfo(struct Student student);
int getMaxTotal(struct Student students[], int size); 
void countingSort(struct Student students[], int size, int exp);
void radixSort(struct Student students[], int size);
void printCPUInfo();
void measureSortingTime(struct Student students[], int size);
void printDataSize(int size);
