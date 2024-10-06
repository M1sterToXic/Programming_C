/*
#include <stdio.h>

int main(){
	int a, n;
	printf("a =");
	scanf("%d", &a);
	for (n=2; n<a; n++){
		if (a%n==0) {
			break;
}
}		if (n==a) {
			puts("1");
}
		else {
			puts("0");
}


}

*/
//////////////////////////////////////////////
/*
#include <stdio.h>

int main(){
	int a, n, b;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
        scanf("%d", &b);
	printf("n == a\n");
	for (n=a; n%a!=0 || n%b!=0; n++);
	printf("n = %d\n", n);
}


*/
//////////////////////////////////////////////

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


