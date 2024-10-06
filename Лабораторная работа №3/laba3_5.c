#include <stdio.h>

int main(void){
	int s, n ,a;
	printf("a = ");
	scanf("%d", &a);
	for (s=0,n=2; n<a; n++) {
		if (a%n==0) {
			s++}
		if (s==0) {
			puts("1");}
		else {
			puts("0");}
}


}
