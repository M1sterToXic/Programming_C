#include <stdio.h>

int main(){
	int n,i,x;
	printf("Введите i: ");
	scanf("%d", &i);
	for(n = 1; n <= i; n++){
		for(x = 1; x <= n; x++){
			printf("%d ", x);}
		printf("\n");}

}
