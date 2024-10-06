#include <stdio.h>

int main(void){
	int a, n;
	printf("a = ");
	scanf("%d", &a);
	for (n=2; n<a && a%n!=0; n++); {
		if (n==a) {
			puts("1");}
		else {
			puts("0");}
}
}

