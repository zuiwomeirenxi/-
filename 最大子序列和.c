#include<stdio.h>
int main()
{
	int a[8] = { 4,-3,5,-2,-1,2,6,-2 };
	int thissum, maxsum;
	thissum = maxsum = 0;
	for (int i = 0; i < 8; i++)
	{
		thissum += a[i];
		if (thissum > maxsum)
			maxsum = thissum;
		else if(thissum<0)
		thissum = 0;
	}
	printf("%d", maxsum);
	return 0;
}