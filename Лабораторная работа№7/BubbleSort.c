#include <stdio.h>

#define V 5
#define G 5
void Print_arrya(int n, int arr[]){
    for( int i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void BubbleSort(int n, int arr[]){

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j +1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

}

int main(){

    int A[5] = {1,7,0,-12,5};
    int B[3] = {6,7,8};

    int C1 [V][G];

    for(int i = 0; i < V; i++){
        for(int j = 0; j < G; j++){
            C1[i][j] = i+j;
        }
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < G; j++){
            printf("%d ", C1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < V; i++){
        for(int j = 0; j < G; j++){
            if( i == j){
                //Главная диагональ равна = 
                printf(" %d /", C1[i][j]);
            }
        }
    }

    printf("\n");

    for(int i = 0; i < V; i++){
        for(int j = 0; j < G; j++){
            if( i == V - 1 - j){
                //Побочная диагональ равна = 
                printf(" %d /", C1[i][j]);
            }
        }
    }

    printf("\n");
    printf("\n");
    BubbleSort(5, A);
    Print_arrya(5, A);
}