#include<stdio.h>
int main()
{}
insert(elementtype x, searchtree t)
{
	if (t == NULL)
	{
		t = malloc(sizeof(struct treenode));//创造一个新节点存放要插入的数据。
		if (t = NULL)
			printf("out of space!!!");//空间不足，创造新节点失败。
		else
		{
			t->element = x;//将要插入的数据放入节点中。
			t->left = t->right = NULL;//插入的节点必须为叶节点，因此将该节点的左右子树指向零。
		}
	}
	else
		if (x < t->element)
			t->left = insert(x, t->left);//如果要插入的值小于该节点的数据，那么在该节点的左边继续插入。
		else if (x > t->element)
			t->right = insert(x, t->right);//与上面情况相反。
		else
			return t;
}