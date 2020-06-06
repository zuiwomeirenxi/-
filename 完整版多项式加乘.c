#include<stdio.h>
#include<stdlib.h>
typedef struct test {
	int zi;
	int xi;
	struct test* next;
}date;
void lian(int a, int b, date** p);
int main()
{
	date* L1, * L2;
	date* sum, * chen;
	void pr(date * L);
	date* cr();
	date* ad(date * L1, date * L2);
	date* mu(date * L1, date * L2);
	L1 = cr();
	L2 = cr();
	sum = ad(L1, L2);
	chen = mu(L1, L2);
	pr(sum);
	printf("\n");
	pr(chen);
	return 0;
}
date* cr()
{
	date* p, * rear;
	int n;
	int c, d;
	date* t;
	printf("请输入有多少项：\n");
	scanf_s("%d", &n);
	p = (date*)malloc(sizeof(date));
	rear = p;
	p->next = NULL;
	while (n--)
	{
		scanf_s("%d%d", &c, &d);
		lian(c, d, &rear);
	}
	t = p; p = p->next; free(t);
	return p;
}
void lian(int a, int b, date** p)
{
	date* d;
	d = (date*)malloc(sizeof(date));
	d->xi = a;
	d->zi = b;
	d->next = NULL;
	(*p)->next = d;
	(*p) = d;
}
date* mu(date* L1, date* L2)
{
	date* t1, * t2, * rear, * t3, * p, * t;
	int c, e;
	t1 = L1;
	t2 = L2;
	if (!t1 || !t2)
		return NULL;
	p = (date*)malloc(sizeof(date));
	p->next = NULL;
	rear = p;
	while (t2)
	{
		lian(t1->xi * t2->xi, t1->zi + t2->zi, &rear);
		t2 = t2->next;
	}
	t1 = t1->next;
	while (t1)
	{
		t2 = L2;
		rear = p;
		while (t2)
		{
			c = t1->xi * t2->xi;
			e = t1->zi + t2->zi;
			while (rear->next && rear->next->zi > e)
				rear = rear->next;
			if (rear->next && rear->next->zi == e)
			{
				if (rear->next->xi + c)
				{
					rear->next->xi += c;
				}
				else
				{
					t3 = rear->next;
					rear->next = t3->next;
					free(t3);
				}
			}
			else
			{
				t3 = (date*)malloc(sizeof(date));
				t3->xi = c;
				t3->zi = e;
				t3->next = rear->next;
				rear->next = t3;
				rear = rear->next;
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	t = p; p = p->next; free(t);
	return p;
}
date* ad(date* L1, date* L2)
{
	date* rear, * t1, * t2, * p, * t3;
	t1 = L1;
	t2 = L2;
	p = (date*)malloc(sizeof(date));
	rear = p;
	p->next = NULL;
	while (t1 && t2)
	{
		if (t1->zi == t2->zi)
		{
			if (t1->xi + t2->xi)
			{
				lian(t1->xi + t2->xi, t1->zi, &rear);
			}
			t1 = t1->next;
			t2 = t2->next;
		}
		else if (t1->zi < t2->zi)
		{
			if (t1->xi || t2->xi)
			{
				lian(t2->xi, t2->zi, &rear);
			}
			t2 = t2->next;
		}
		else if (t1->zi > t2->zi)
		{
			if (t1->xi || t2->xi)
			{
				lian(t1->xi, t1->zi, &rear);
			}
			t1 = t1->next;
		}
	}
	while (t1)
	{
		lian(t1->xi, t1->zi, &rear);
		t1 = t1->next;
	}
	while (t2)
	{
		lian(t2->xi, t2->zi, &rear);
		t2 = t2->next;
	}
	t3 = p;
	p = p->next;
	free(t3);
	return p;
}
void pr(date* L)
{
	int flag = 0;
	if (!L)
	{
		printf("0 0");
		return;
	}
	while (L)
	{
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", L->xi, L->zi);
		L = L->next;
	}
	return;
}

