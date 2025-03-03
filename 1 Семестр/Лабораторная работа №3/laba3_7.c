#include <stdio.h>

int main(void){
	int a, n = 2, flag = 0;
	printf("a = ");
	scanf("%d", &a);
	while(a%n!=0){
		n++;
		printf("n = %d\n", n);
        	if (n==a) {
			flag = 1;
			printf("flag = %d\n", flag);
			break;}
}




}
