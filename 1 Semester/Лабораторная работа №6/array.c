/*
#include <stdio.h>
int main(){
    int test_score[3];
    float cnt;
    scanf("%f", &cnt );
    test_score [0] = 100;
    test_score [1] = 77;
    test_score [2] = -42;
    int sum = 0;
    for( int i = 0; i < cnt; i++){
        sum += test_score[i]; // 0,1,2
    }

    printf("my avg score = %f\n", sum / cnt);

    return 0;

}
*/
 
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

 /*
#define N 5

int a [N];
int b[5] = {1,2,3,4,5};
float c [] = {1.5, 3.2, 2.5};
int d[5] = {[3] = 9};
int e[N] = {()};
 */

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

/*
int a[5] = {5,6,7,8,9};
int b[5] = {1,2,3,4,5};

b = a; //ERROR
a = {5,3}; //ERROR
a[2] = -17;//Ok
a[0] = b[4];/Ok
a[2.5] = 33;//ERROR
b[4000] = 100;//Error,segflault
a[-1] = 8;//Ok, possible segflaut
*/


#include <stdio.h>

int main(){

    int a[5];
    int n = sizeof[a]/sizeof(int); // вычесляет размер массива
    
    return 0;
}



