#include<stdio.h>
#include<string.h>
int main()
{
	void pai(char* a[], int n);
	void pri(char* b[], int n);
	char* p[] = { "fellow","hello","world" };
	int n = 3;
	pai(p, n);
	pri(p, n);
	return 0;
}
void pai(char* a[], int n)
{
	int i, j;
	char* t;
	for (i = 0; i++; i < n)
	{
		for (j = i + 1; j++; j < n - 1)
		{
			if (strcmp(a[i], a[j]) > 0)
				continue;
			else
				t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
}
void pri(char* b[], int n)
{
	//printf("%p\n", b);
	for(int i=0;i<n;i++)
	printf("%s ", *b++);
	//printf("\n");
	//printf("%p", b -1);
	printf("%d", sizeof(b));
}