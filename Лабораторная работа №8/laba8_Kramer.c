#include <stdio.h>
#include <math.h>

//Определитель
double f(int n, double a[n][n]){
    if (n == 1){
        return a[0][0];
    }
    double sum = 0;
    for(int i = 0; i < n; i++){
        double g[n-1][n-1];
        int y = 0;
        for(int j = 1; j < n; j++){
            y = 0;
            for(int h = 0; h < n; h++){
                if (h == i){
                    continue;
                    
                }
                g[j - 1][y] = a[j][h];
                y++;
            }
        }
        sum += pow(-1, i) * a[0][i] * f(n-1, g);
    }
    return sum;

}
//Новая матрица S заменяя m столбцы на b
void pc(int m, int n,double b[n], double a[n][n], double s[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == m){
                s[i][j] = b[i];
            } else{
                s[i][j] = a[i][j];
            }
        }
    }


}

int main(){
    int n;
    printf("Введите n = ");
    scanf("%d", &n);
    double a[n][n];
    double b[n];
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Элементы [%d][%d]", i+1,j+1);
            scanf("%lf", &a[i][j]);
        }
        printf(" равно чему =");
        scanf("%lf", b+i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%0.2lf ", a[i][j]);
        }
        printf(" = %0.2lf", b[i]);
        printf("\n");
    }

    double dilta = f(n ,a);
    if(dilta == 0){
        printf("Нет единственного решения");
        return 1;
    }
    for(int i = 0; i < n; i++){
        double l[n][n];
        pc(i, n, b, a, l);
        printf("x%d = %0.2lf\n", i+1, f(n ,l)/dilta);
    }
    return 0;
}