/*
#include <stdio.h>

int main(){
    int n,m;
    int x[n];
    int y[m];
    printf("Введите n и m = ");
    scanf("%d %d", &n,&m);
    printf("n = %d  m = %d\n", x, y);
}
*/

#include <stdio.h>
int main(){
    int max = 0;
    int min;
    int s;
    int b;
    int f = s;
    float sum = 0;
    printf("Введите s = ");
    scanf("%d", &s);
    printf("Введите b = ");
    scanf("%d", &b);
        int cnt = b;

    int z[f];
    int x[s];
    int y[b];
    for(int i = 0; i < s; i++){
        scanf("%d", &x[i]);
        printf("x = %d\n", x[i]);
    }
    for(int i = 0; i < b; i++){
        scanf("%d", &y[i]);
        printf("y = %d\n", y[i]);
    }
    for(int i = 0; i < f; i++){
        z[i] = 0;
    }
    min = z[0];

   for( int i = 0; i < s; i++){ // z = ...
        z[i] = (x[i] + y[i]);     // 0,1,2
        printf("z[i] = %d ", z[i]);
        if(z[i] > max){
            max = z[i];
        } 
        if(z[i] < min){
            min = z[i];
        }
    }
    printf("\n");
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    for( int i = 0; i < s; i++){
        sum += z[i];
    }
    printf("sum = %f\n", sum);
    printf("cnt = %d\n", cnt);

    printf("my avg score = %f\n", sum / cnt);
    return 0;
}


    /*
    int x [3];
    int y [3];
    float cnt;
    scanf("%f", &cnt );
    x [0] = 100;
    x [1] = 77;
    x [2] = -42;
    y [0] = 40;
    y [1] = 32;
    y [2] = -2;
    int sum = 0;
    */
    /*
    for( int i = 0; i < cnt; i++){
        sum += test_score[i]; // 0,1,2
    }
    */