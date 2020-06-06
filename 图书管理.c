#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 100
#define fopen fopen_s
#define sleep Sleep
#define pr printf("图书编号为：%d\n书名为：%s\n作者为：%s\n出版日期为：%s\n出版fn为：%s\n出版社为:%s\n价格为：%f\n", stu[i].num, stu[i].name, stu[i].author, stu[i].day, stu[i].fn, stu[i].place, stu[i].money)
typedef struct {
	int num;
	char name[100];
	char author[100];
	char fn[5];
	char place[20];
	char day[15];
	float money;
}date;
date stu[MAX];
int s[1] = { 0 };
int main()
{
	void input();
	void display();
	void find();
	void modify();
	void change();
	void comp();
	int n;
		system("COLOR 3f");
		printf("\n");
		printf("\t\t\t\t*********************************\n");
		sleep(50);
		printf("\n");
		printf("\t\t\t\t |欢迎来到图书管理系统|\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 主菜单             |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 1.图书信息录入     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 2.图书信息浏览     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 3.图书信息修改     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 4.图书信息查询     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 5.图书信息删除     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 6.退出系统         |\n");
		sleep(50);
		printf("\n");
		sleep(50);
		printf("\t\t\t\t**********************************\n\n");
		sleep(300);
		printf("请输入需要办理项目的编号（1—6）：");
		scanf_s("%d", &n);
		printf("\n\n\n\n");
		if (n > 0 && n < 7)
		{
			while (1)
			{
				switch (n)
				{
				case 1:input(); break;
				case 2:display(); break;
				case 3:change(); break;
				case 4:find(); break;
				case 5:modify(); break;
				case 6:comp(); break;
				default:printf("请输入正确的编号！");
				}
				printf("请继续输入需要办理业务的编号:");
				scanf_s("%d", &n);
			}
		}
		else
			printf("请输入正确的编号！");
	return 0;
}
void input()
{
	FILE* fp;
	FILE* fp1;
	char g=1;
	int n;
	int count = 0;
	int i;
	fopen(&fp,"date.txt", "ab");
	 fopen(&fp1,"s.txt", "ab");
	 fread(s, sizeof(int), 1, fp1);
	 i = s[0];
	printf("%p\n", fp);
	while (g!= '#')
	{
		printf("请输入要录取图书的数目：\n");
		scanf_s("%d", &n);
		for ( i; i < n+s[0]; i++)
		{
			printf("请依次输入图书序号 书名 作者名 分类号 出版单位 出版时间 价格\n");
			scanf_s("%d", &stu[i].num);
			scanf_s("%s", stu[i].name, 100);
			scanf_s("%s", stu[i].author,50);
			scanf_s("%s", stu[i].fn,5);
			scanf_s("%s", stu[i].place, 20);
		    scanf_s("%s", stu[i].day, 15);
			scanf_s("%f", &stu[i].money);
			fwrite(&stu[i], sizeof(date), 1, fp);
		}
		printf("录入成功，请继续输入，如需退出请输入#\n");
		g = getchar();
		g = getchar();
		s[0] = n+s[0];
		fwrite(s, sizeof(int), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
}
void display()
{
	FILE* fp;
	FILE* fp1;
	 fopen(&fp,"date.txt", "r");
	fopen(&fp1,"s.txt", "r");
	fread(s, sizeof(int), 1, fp1);
	for (int i = 0; i < s[0]; i++)
		fread(&stu[i], sizeof(date), s[0], fp);
	printf("%d", s[0]);
	int x;
	int z;
	while (getchar() != '#')
	{
		printf("请输入需要查看的图书序号：");
		scanf_s("%d", &x);
		for (int j = 0; j < s[0]; j++)
		{
			if (stu[j].num = x)
				z = j;
			break;
		}
		printf("图书编号为：%d\n书名为：%s\n作者为：%s\n出版日期为：%s\n出版fn为：%s\n出版社为:%s\n价格为：%f\n", stu[z].num, stu[z].name, stu[z].author, stu[z].day, stu[z].fn, stu[z].place, stu[z].money);
		printf("如需继续查询，请继续输入,如需结束查询，请输入#：");
		getchar();
	}
	fclose(fp);
	fclose(fp1);
}
void find()
{
	FILE* fp;
	FILE* fp1;
	 fopen(&fp,"date.dat", "r");
	fopen(&fp1,"s.dat", "r");
	fread(&s, sizeof(int), 1, fp1);
	for (int c = 0; c < s[0]; c++)
		fread(&stu[c], sizeof(date), s[0], fp);
	int k = 0;
	char na[100];
	int j,i;
		while (getchar() != '#')
		{
			printf("请输入需要查询的书籍名：");
			scanf_s("%s", na,100);
			for (i = 0; i < s; i++)
			{
				if ((strcmp(na, stu[i].name) != 0)&&i==s)
					printf("not find this book");
				else if(strcmp(na,stu[i].name)==0)
					pr;
			}
			printf("如需继续查询请继续输入，否则输入#结束。");
			getchar();
		}
		fclose(fp);
		fclose(fp1);
}
void modify()
{
	FILE* fp;
	FILE* fp1;
	int n;
	int x;
	int i;
	 fopen(&fp,"date.dat", "ab+");
	 fopen(&fp1,"da.dat", "ab+");
	rewind(fp);
	printf("请输入需要删除的图书序号：");
	fread(s, sizeof(int), 1, fp1);
	for (i = 0; fread(&stu[i], sizeof(date), 1, fp) == 1; i++);
	while (getchar() != '#')
	{
		scanf_s("%d", &n);
		for( i=0;i<s[0];i++)
			if (n == stu[i].name)
			{
				x = i;
				for (x; x < s[0]- i; x++)
					stu[x] = stu[x + 1];
				printf("删除成功！");
				s[0] = s[0] - 1;
				for (i = 0; i < s[0]; i++)
					fwrite(&stu[i], sizeof(date), 1, fp);
				break;
			}
		if (i ==s[0])
			printf("该图书序号不存在。");
		printf("请继续输入要删除的图书序号，或者输入#结束删除");
	}
	fclose(fp);
	fclose(fp1);
}
void change()
{
	FILE* fp;
	FILE* fp1;
	fopen_s(&fp, "date.dat", "rb+");
	fopen_s(&fp1, "s.dat", "rb+");
	fread(s, sizeof(int), 1, fp1);
	for (int v = 0; v < s[0]; v++)
		fread(&stu[v], sizeof(date), s, fp);
	int i = 0;
	int n;
	while (getchar() != '#')
	{
		printf("请输入需要修改的图书序号：");
		scanf_s("%d", &n);
		for (i=0; i < s[0]; i++)
		{
			if (stu[i].num == n)
			{
				printf("请输入新的图书信息：\n");
				scanf_s("%d%s%s%s%s%s%f", &stu[i].num, stu[i].name, stu[i].author, stu[i].place, stu[i].day, stu[i].fn, &stu[i].money);
				break;
			}
			if (i == s[0])
				printf("not found\n");
		}
		printf("请继续修改或输入#结束修改");
		getchar();
	}
	fclose(fp);
	fclose(fp1);
}
void comp()
{
	exit(0);
}
