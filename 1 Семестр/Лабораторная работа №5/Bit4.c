#include <stdio.h>

int main(){
    unsigned int k, a;
    printf("Введите число a:");
    scanf("%u", &a);
    printf("Введите шаги k:");
    scanf("%u", &k);
    //Двоичная система числа
    for(int i = sizeof(a)*8-1; i >= 0; i--){
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
    if(k%2==0){
        k >> 1;
    }

    //Сдвигаем влево на k
    unsigned int result = (a << k) | (1 << k) - 1; 
    
    //Двоичная система числа
    for(int i = sizeof(result)*8-1; i >= 0; i--){
            printf("%d", (result >> i)&1);
    }
    
}