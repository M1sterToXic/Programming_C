/*

// Копируем массив в другой

#include <stdio.h>

int main(void){
    float func_1[100] = {2.3, -4.3, 6.9, -12.4, 120.4};
    float func_2[50];
    int size_1 = sizeof(func_1) / sizeof(func_1[0]);
    int size_2 = sizeof(func_2) / sizeof(func_2[0]);
    int size = (size_1 < size_2) ? size_1 : size_2;

    for (int i = 0; i < size; ++i){
        func_2[i] = func_1[i];
    }

    for (int i = 0; i < size; ++i){
        printf("%.2f ", func_2[i]);
    }

    return 0;
}
*/

/*

//Вставка в массив

#include <stdio.h>

#define TOTAL_MARKS 10

int main(void){
    int marks[TOTAL_MARKS] = {3,2,5};
    int index = 2;

    for(int i = TOTAL_MARKS - 1; i > index; i--){
        marks[i] = marks[i-1];
        printf("marks[%d] = marks[%d]\n", i, i-1);
    }

    marks[index] = 4;

    for(int i = 0; i < TOTAL_MARKS; i++){ 
        printf("%d ", marks[i]);
    }
}
*/

/*
#include <stdio.h>

int main(){
    int m[3] = {1,2};
    int j = 2;
    m[j] = 9;
    for(int i = 0; i < 3; i++){
        printf("%d ", m[i]);
    }
}
*/


/*
#include <stdio.h>

#define TOTAL_MARKS 10

int main(void){
    int marks[TOTAL_MARKS] = {3,2,4,5,9,7,8};
    int del_index = 3;

    for(int i = del_index; i < TOTAL_MARKS-1; i++){
        marks[i] = marks[i+1];
        printf("marks[%d] = marks[%d]\n", i, i+1);
    }

    //Отображаем результирующий массив
    for(int i = 0; i < TOTAL_MARKS; i++){ 
        printf("%d  ", marks[i]);
    }
}
*/

/*
#include <stdio.h>

int main(){
    char sp[] = "Из заданного предложения, начиная c первой встретившейся буквы \'а\', скопировать в подстроку все символы до первой встретившейся буквы \'к\'.";
    printf("sp = %s\n", sp);
    char bf[10];

    scanf("%s", bf);
    puts(bf);

    fgets(bf,sizeof(bf),stdin);
    puts(bf);
}
*/
