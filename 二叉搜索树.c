#include<stdio.h>
int main()
{}
insert(elementtype x, searchtree t)
{
	if (t == NULL)
	{
		t = malloc(sizeof(struct treenode));//����һ���½ڵ���Ҫ��������ݡ�
		if (t = NULL)
			printf("out of space!!!");//�ռ䲻�㣬�����½ڵ�ʧ�ܡ�
		else
		{
			t->element = x;//��Ҫ��������ݷ���ڵ��С�
			t->left = t->right = NULL;//����Ľڵ����ΪҶ�ڵ㣬��˽��ýڵ����������ָ���㡣
		}
	}
	else
		if (x < t->element)
			t->left = insert(x, t->left);//���Ҫ�����ֵС�ڸýڵ�����ݣ���ô�ڸýڵ����߼������롣
		else if (x > t->element)
			t->right = insert(x, t->right);//����������෴��
		else
			return t;
}