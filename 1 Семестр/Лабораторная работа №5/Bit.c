#include <stdio.h>

int main(){
    int x;
    int c = 0,n = 0;
    int b = 65536;
    int bit = b;
    for(int i = sizeof(b)*8-1; i >= 0; i--){
        printf("%d", x = (b >> i)&1);
        if (x == 1){
            c += 1;
        }
        else{
            n += 1;
        }
    }
    printf("\n");
    printf("bit = %d\n", bit);
    printf("c = %d  n = %d", c,n);

    // 0000000000000000000 101
    // 0000000000000000000 001
    // 0000000000000000000 001
    // int bit = b &1;

}