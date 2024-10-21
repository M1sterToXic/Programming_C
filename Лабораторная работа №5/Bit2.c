#include <stdio.h>

int main(){
    int c;
    scanf("%d", &c);
    printf("c = %d -c = %d\n", c, ~c);
    for(int i = sizeof(c)*8-1; i >= 0; i--){
        printf("%d", (c >>i)&1);
    }
    printf("\n");
    for(int i = sizeof(c)*8-1; i >= 0; i--){
        printf("%d", (~c >> i)&1);
        
    }
    printf("\n");
    printf("%d %d\n", c, ~c);
}