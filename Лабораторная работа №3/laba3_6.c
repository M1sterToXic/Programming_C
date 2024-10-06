#include <stdio.h>

int main(void){
	int s,n,a;
	printf("a = ");
	scanf("%d", &a);
	for (s=0,n=2; n<a; n++) {
		if (a%n==0) {
			s=1;
			printf("s = %d\n", s);
			break;}
}


}
