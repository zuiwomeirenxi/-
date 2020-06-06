#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* a;
	int number;
	printf("ÇëÊäÈëÊıÁ¿£º");
	scanf_s("%d", &number);
	a = (int*)malloc(number * sizeof(int));
	for (int i = 0; i < number; i++)
		scanf_s("%d", &a[i]);
	printf("\n");
	for (int i = number - 1; i >= 0; i--)
		printf("%d ", a[i]);
		free(a);
		return 0;
}