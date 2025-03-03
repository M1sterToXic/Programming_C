#include <stdio.h>

int main(){
	int year;
	printf("enter num: ");
	scanf("%d", &year);
	if (year%400==0)
{
		printf("yes\n");
}
	else if(year%100==0)
{
		printf("Не високостный\n");
}
	else if(year%4==0)
{
		printf("Високостный\n");
}
	else
{
		printf("no\n");
}

}
