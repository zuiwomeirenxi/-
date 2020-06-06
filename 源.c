#include<stdio.h>
int main()
{
	//int s ;
	int* p;
	int* d;
	int* c;
	int* serch(int*x);
	int a[3][4] = { {34,60,65,78},{30,87,60,60},{34,47,23,65} };
	//printf("请输入要查询的学号：");
	//scanf_s("%d", &s);
	for(int i=0;i<3;i++)
	{
		p = serch(*(a+i));
		if (p != NULL)
		{
			for (int i = 0; i < 4; i++)
				printf("%d ", *(p++));
			printf("\n");
		}
	}
	//for (int i = 0; i < 4; i++)
		//printf("%d ", *(p++));
	return 0;
}
int* serch(int*x)
{
	int* t;
	t = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (*(x++) < 60)
		{
			t = x- i -1;
			break;
		}
	}
	return t;
}