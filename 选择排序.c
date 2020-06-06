#include<stdio.h>
int main()
{
	void xuan(int a[], int n);
	int b[5],i;
	printf("ÇëÊäÈëÊı×Ö£º");
	for ( i = 0; i < 5; i++)
		scanf_s("%d", &b[i]);
	xuan(b, 5);
	for ( i = 0; i < 5; i++)
		printf("%d ", b[i]);
	return 0;
}
void xuan(int a[], int n)
{
	int t = 0;
	int k = 0;
	int j = 0;
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		//k = i;
		for (j = i+1; j < n; j++)
		{
			printf("%d\n", i);
			if (a[j] < a[i])
			{	//k = j;
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
		}
	}
}