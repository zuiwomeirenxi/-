#include<stdio.h>
#include<stdlib.h>
typedef struct chen{
	long num;
	float sorce;
	struct chen* next;
}date;
int n;
date* creat(void)
{
	date* head;
	date* p1, * p2;
	n = 0;
	p1 = p2 = (date*)malloc(sizeof(date));
	scanf_s("%ld%f", &p1->num, &p1->sorce);
	head = NULL;
	while (p1->num!=0)
	{
		++n;
		if (n == 1)
			head = p1;
		else
		{
			p1 = (date*)malloc(sizeof(date));
			p2->next = p1;
			p2 = p1;
			scanf_s("%ld%f", &p1->num, &p1->sorce);
		}
	}
	p2->next = NULL;
	return(head);
}
void print(date* he)
{
	date* p;
	p = he;
	if(p!=NULL)
		do
		{
			printf("%ld %.2f\n", p->num, p->sorce);
			p = p->next;
		} while (p->next);
}
int main()
{
	date* t;
	t = creat();
	print(t);
	return 0;
}
//成功（编写时注意输入的格式）