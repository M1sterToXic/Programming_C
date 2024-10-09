#include <stdio.h>

int main()
{
	float a;
	float b;
	char ch;
	printf("Введите F или C\n");
	printf("Input Temperature: ");
	scanf("%f%c", &a, &ch);
	if (ch == 'c' || ch == 'C')
	{
		b = ((a * 1.8) + 32);
		printf("b = %f\n", b);

		
	}
	else if (ch == 'f' || ch == 'F')
	{
		b = ((a - 32.0) / 1.8);
		printf("b = %f\n", b);
	}
	else
	{
		printf("Error\n");
	}
}
