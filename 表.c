#include<stdio.h>
typedef struct test {
	int a;
	struct test* b;
}date;
int main()
{
	int isempty(date * a);
	date* find(int x, date * a);
	void deleat(int x, date * a);
	void insert(int x, date * a, date * b);
	date* findprevious(int x, date * a);
	void deletelist(date * a);
	int n = 0;
	date* p1;
	date* p2;
	date* head;
	p1 = p2 = (date*)malloc(sizeof(date));
	scanf_s("%d", &p1->a);
	head = NULL;
	while (p1->a != 0)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			p2->b = p1;
		p2 = p1;
		p1 = (date*)malloc(sizeof(date));
		scanf_s("%d", &p1->a);
	}
	printf("%d", isempty(head));
	printf("%p", find(2, head));
	deleat(3, head);
	insert(3, head, findprevious(3, head));
	deletelist(head);
	return 0;
}

int isempty(date* a)
{
	return a->a == NULL;
}

int islast(date* a)
{
	return a->b == 0;
}

date* find(int x, date* a)
{
	date* p;
	p = a->b;
	while (p != NULL && p->a != x)
	{
		p = p->b;
	}
	return p;
}

void deleat(int x, date* a)
{
	date* findprevious(int x, date * a);
	date* p, * tem;
	p = findprevious(x, a);
	if (!islast(p, a))
	{
		tem = p->b;
		p->b = tem->b;
		free(tem);
	}
}

date* findprevious(int x, date* a)
{
	date* p;
	p = a;
	while (p->b != NULL && p->b->a != x)
	{
		p = p->b;
	}
	return p;
}

void insert(int x, date* a, date* b)
{
	date* tem;
	tem = (date*)malloc(sizeof(date));
	if (tem = NULL)
		printf(" out of space");
	tem->a = x;
	tem->b = b->b;
	b->b = tem;
}

void deletelist(date* a)
{
	date* p, * tem;
	p = a->b;
	a->b = NULL;
	while (p != NULL)
	{
		tem = p->b;
		free(p);
		p = tem;
	}
}