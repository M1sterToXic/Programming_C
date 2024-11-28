// Вариант 14
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Создания матрицы рандомно
void random_matrix(int size, double arr[size][size])
{
    srand(time(NULL));
    double **matrix = (double **)malloc(size * sizeof(double));
    for(int i = 0; i < size; i++){
        matrix[i] = (double *)malloc(size * sizeof(double));
    }
    


    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = (rand() % 21) - 10 +((rand() % 100) / 100.0);
        }
    }

    

    printf("\n");
    printf("Отображение случайной матрицы\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf(" [%0.2lf] ", arr[i][j] = matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }

    free(matrix);
}


// Проверка на коректность ввода char
char char_input()
{
    char human;
    while(1){
        printf("Вы хотите заполнить матрицу рандомно? Y|N: ");
        if(scanf(" %c", &human) == 1 && (human == 'Y' || human == 'N')){
            return human;
        } else{
            printf("Введите корректные данные: Y|N ");
            while(getchar() != '\n');
        }
    }
}


// Проверка на корректность int
int input_int()
{
    int value;
    while(1){
        if(scanf("%d", &value) == 1 ){
            if(value >= 0){
                return value;
            } else{
                printf("Ошибка! Введите целое число больше или равное 0: ");
            }
        } else{
            printf("Неккоректный ввод! Введите снова: ");
            while(getchar() != '\n');
        }
    }
}


// Проверка на корректность double
double input_double()
{
    double value;
    while(1){
        if(scanf("%lf", &value) == 1){
            return value;
        } else{
            printf("Неккоректный ввод!\n");
            while(getchar() != '\n');
        }
    }
}

void bubble_sort( int size, double arr[size][size], int counter[size])
{   
    
    for(int col = 0; col < size; col++){
        // Добавляем счётчик для сравнения где было больше  сравнений
        counter[col] = 0;
        int swapped;
        do {
            swapped = 0;
            for(int row = 0; row < size - 1; row++){
                if(arr[row][col] < arr[row + 1][col]){
                    double temp = arr[row][col];
                    arr[row][col] = arr[row + 1][col];
                    arr[row + 1][col] = temp;
                    counter[col]++;
                    swapped = 1;
                }
            }
        } while(swapped);
    }


    // Отображение матрицы после сортировки
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf(" %0.2lf  ", arr[i][j]);
        }
        printf("\n");
    }

}


// Функция для поиска столбца с максимальным количеством сравнений и подсчёта суммы положительных элементов в этом столбце
void max_counter(int size, int counter[size], double arr[size][size])
{
    int max_count = counter[0];
    int max_column = 0;

    //Столб где больше всего сравнений
    for(int i = 0; i < size; i++){
        if(counter[i] > max_count){
            max_count = counter[i];
            max_column = i;
        }
    }

    double sum_positive = 0;
    for(int i = 0; i < size; i++){
        if(arr[i][max_column] > 0){
            sum_positive += arr[i][max_column];
        }
    }

    printf("\n");
    printf("Столбец с наибольшим количеством сравнений: %d (Сравнений: %d)\n", max_column + 1, max_count);
    printf("Сумма положительных элементов в этом столбце: %.2lf\n", sum_positive);
}


// Создаём обратную главную диагональ
void reverse_main_diagonal(int size, double arr[size][size])
{
    // Динамически выделяем память для хранения элементов главной диагонали
    double *diagonal = (double *)malloc(size * sizeof(double));
    if(diagonal == NULL){
        printf("Ошибка выделения памяти!");
        return;
    }

    for(int i = 0; i < size; i++){
        diagonal[i] = arr[i][i];
    }

    // Производим замену диагонали
    for(int i = 0; i < size; i++){
        arr[i][i] = diagonal[size - 1 - i];
    }

    // Освобождаем память
    free(diagonal);

    printf("\nМатрица после изменения главной диагонали\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf(" [%.2lf] ", arr[i][j]);
        }
        printf("\n");
    }
}


// Тело
int main()
{
    int m;
    printf("Матрица  n x n будет = ");
    m = input_int(); 
    char human;
    human = char_input();

    double a[m][m];
    int counter[m];

    if(human == 'N'){

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                printf("a[%d][%d] = ", i, j);
                a[i][j] = input_double();
            }
            printf("\n");
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                printf(" [%0.2lf] ", a[i][j]);
            }
            printf("\n");
        }
    } else if(human == 'Y'){
        random_matrix(m, a);
    }


    printf("\n");
    printf(" Отсортированная матрица\n");
    bubble_sort( m,a,counter);

    // Где, сколько раз было сравнение
    printf("\n");
    for(int i = 0; i < m; i++){
        printf(" Столбец %d: %d сравнений\n", i + 1, counter[i]);
    }

    // Сравнение и сумма
    max_counter(m, counter, a);

    // Смотрим на обратную главную диагональ :>
    reverse_main_diagonal(m, a);
    return 0;

}


























/*
int main(){
    int k, l;
    printf("Введите k ");
    scanf("%d", &k);
    printf("Введите l ");
    scanf("%d", &l);
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= l; j++){
            printf("%d = %d*%d = %d\t ", i, i, j, i*j);
        }
        printf("\n");
    }


}
*/

/*
double sq4_x(double x)
{
    int res = (x < 0) ? NAN : pow(x, 0.25);
    return res;

}

int main(){
    printf("%f\n", sq4_x(16));
}
*/

