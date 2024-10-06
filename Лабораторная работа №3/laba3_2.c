#include <stdio.h>

int main(void){
        int a, n, b;
        printf("a = ");
        scanf("%d", &a);
        printf("b = ");
        scanf("%d", &b);
        printf("n == a\n");
        for (n=a; n%a!=0 || n%b!=0; n++);
        printf("n = %d\n", n);
}
