#include <stdio.h>

int main(void){
        int i, n1, n2;
        printf("n1, n2 = ");
        scanf("%d %d", &n1, &n2);
        printf("i == n1\n");
        for (i=n1; !(n1 % i ==0 && n2 % i ==0); i--);
{
        printf("i = %d", i);
}

}
