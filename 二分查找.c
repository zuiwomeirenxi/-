#include<stdio.h>
int ser(const int a[], int b, int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (a[mid] < b)
			low = mid ;
		else if (a[mid] > b)
			high = mid ;
		else
			return mid;
	}
	return -1;
}
	
	int main()
	{
		int i;
		int c[5] = { 1,2,3,3,5 };
		i=ser(c, 3, 5);
		if (i != -1)
			printf("%d", i);
		else
			printf("not found");
		return 0;
	}