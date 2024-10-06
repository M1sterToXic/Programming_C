#include <stdio.h>

int main(){
	int n,i,x;
	printf("Введите число n: ");
	scanf("%d", &n);
	for(x = 1, i = 1; i <= n*n; i++){
		printf("%d ", i);
		if(i == n*x){
			printf("\n");
			x+=1;
			}

}

}

