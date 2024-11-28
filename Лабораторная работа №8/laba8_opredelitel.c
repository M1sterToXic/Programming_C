#include <stdio.h>

double pow1(double n, unsigned long long b){
    double p = 1.0;
    while( b != 0){
        if((b & 1) != 0){
            p *= n;
        }
        n *= n;
        b >>= 1;
    }
    //printf("%lf", p);
    return p;
}

double divider(double r, double h, int k, int l[k][k], int c[k]){
    if (k == 1){
        return l[0][0];
    }
    double sum = 0;
    for(int i = 0; i < k; i++){
            
    }

}

int main(){
    double n;
    int b;
    printf("Введите n: ");
    scanf("%lf", &n);
    printf("Введите b: ");
    scanf("%d", &b);
    
    //Инициализация Функции pow1
    printf("pow1 = %lf\n", pow1(n, b));

    //Создаем Матрицу NxN
    int k;
    printf("Какой размер матрицы?: ");
    scanf("%d", &k);
    double r;
    double h;
    int l[k][k];
    int c[k];
    //Вводим значение матрицы
    for(int i = 1; i <= k; i++){
        for(int g = 1; g <= k; g++){
            printf("Введите матрицу l[%d][%d]", i, g);
            scanf("%lf", &r);
        }
        printf("Чему равно?:");
        scanf("%lf", &h);
        printf("\n");
    }
}
