#include <stdio.h>
#include <math.h>

double my_sqrt(a){
    
} 

int main(){
    int a,b;
    char s;
    printf("Input: ");
    scanf("%d%c%d", &a,&s,&b);
    printf("%d %c %d\n", a, s, b);

    switch(s) {
        case '+':
            printf("%d\n", a+b);
            break;
        case '-':
            printf("%d\n", a-b);
            break;
        case '*':
            printf("%d\n", a*b);
            break;
        case '/':
            printf("%d\n", a/b);
            break;
        case '^':
            printf("%lf\n", pow(a, b))
        case 'S':
            printf();
        default:
    }
}