#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 100
#define fopen fopen_s
#define sleep Sleep
#define pr printf("ͼ����Ϊ��%d\n����Ϊ��%s\n����Ϊ��%s\n��������Ϊ��%s\n����fnΪ��%s\n������Ϊ:%s\n�۸�Ϊ��%f\n", stu[i].num, stu[i].name, stu[i].author, stu[i].day, stu[i].fn, stu[i].place, stu[i].money)
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
		printf("\t\t\t\t |��ӭ����ͼ�����ϵͳ|\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | ���˵�             |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 1.ͼ����Ϣ¼��     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 2.ͼ����Ϣ���     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 3.ͼ����Ϣ�޸�     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 4.ͼ����Ϣ��ѯ     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 5.ͼ����Ϣɾ��     |\n");
		sleep(50);
		printf("\t\t\t\t |                    |\n");
		sleep(50);
		printf("\t\t\t\t | 6.�˳�ϵͳ         |\n");
		sleep(50);
		printf("\n");
		sleep(50);
		printf("\t\t\t\t**********************************\n\n");
		sleep(300);
		printf("��������Ҫ������Ŀ�ı�ţ�1��6����");
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
				default:printf("��������ȷ�ı�ţ�");
				}
				printf("�����������Ҫ����ҵ��ı��:");
				scanf_s("%d", &n);
			}
		}
		else
			printf("��������ȷ�ı�ţ�");
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
		printf("������Ҫ¼ȡͼ�����Ŀ��\n");
		scanf_s("%d", &n);
		for ( i; i < n+s[0]; i++)
		{
			printf("����������ͼ����� ���� ������ ����� ���浥λ ����ʱ�� �۸�\n");
			scanf_s("%d", &stu[i].num);
			scanf_s("%s", stu[i].name, 100);
			scanf_s("%s", stu[i].author,50);
			scanf_s("%s", stu[i].fn,5);
			scanf_s("%s", stu[i].place, 20);
		    scanf_s("%s", stu[i].day, 15);
			scanf_s("%f", &stu[i].money);
			fwrite(&stu[i], sizeof(date), 1, fp);
		}
		printf("¼��ɹ�����������룬�����˳�������#\n");
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
		printf("��������Ҫ�鿴��ͼ����ţ�");
		scanf_s("%d", &x);
		for (int j = 0; j < s[0]; j++)
		{
			if (stu[j].num = x)
				z = j;
			break;
		}
		printf("ͼ����Ϊ��%d\n����Ϊ��%s\n����Ϊ��%s\n��������Ϊ��%s\n����fnΪ��%s\n������Ϊ:%s\n�۸�Ϊ��%f\n", stu[z].num, stu[z].name, stu[z].author, stu[z].day, stu[z].fn, stu[z].place, stu[z].money);
		printf("���������ѯ�����������,���������ѯ��������#��");
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
			printf("��������Ҫ��ѯ���鼮����");
			scanf_s("%s", na,100);
			for (i = 0; i < s; i++)
			{
				if ((strcmp(na, stu[i].name) != 0)&&i==s)
					printf("not find this book");
				else if(strcmp(na,stu[i].name)==0)
					pr;
			}
			printf("���������ѯ��������룬��������#������");
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
	printf("��������Ҫɾ����ͼ����ţ�");
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
				printf("ɾ���ɹ���");
				s[0] = s[0] - 1;
				for (i = 0; i < s[0]; i++)
					fwrite(&stu[i], sizeof(date), 1, fp);
				break;
			}
		if (i ==s[0])
			printf("��ͼ����Ų����ڡ�");
		printf("���������Ҫɾ����ͼ����ţ���������#����ɾ��");
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
		printf("��������Ҫ�޸ĵ�ͼ����ţ�");
		scanf_s("%d", &n);
		for (i=0; i < s[0]; i++)
		{
			if (stu[i].num == n)
			{
				printf("�������µ�ͼ����Ϣ��\n");
				scanf_s("%d%s%s%s%s%s%f", &stu[i].num, stu[i].name, stu[i].author, stu[i].place, stu[i].day, stu[i].fn, &stu[i].money);
				break;
			}
			if (i == s[0])
				printf("not found\n");
		}
		printf("������޸Ļ�����#�����޸�");
		getchar();
	}
	fclose(fp);
	fclose(fp1);
}
void comp()
{
	exit(0);
}
