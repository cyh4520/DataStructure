// Huffman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>
typedef struct treeNode
{
	int num;
	struct treeNode *left;
	struct treeNode *right;
}node;

node* creatNode(int x)
{
	node *leaf = new node();
	leaf->num = x;
	leaf->left = NULL;
	leaf->right = NULL;
	return leaf;
}

int arr[7] = { 10, 15, 12, 3, 4, 13, 1 };
int visit[7] = { 0 };
node *lvs[7];
void init()
{
	for (int i = 0; i < 7; i++)
	{
		lvs[i] = creatNode(arr[i]);
	}
}
void findMin()
{
	int i, j;
	int flagi,flagj;
	int tempi=1000,tempj=1000;
	//这里找两个最小的可以用堆实现
	for (i = 0; i < 7; i++)
	{
		if (lvs[i]!=NULL&&lvs[i]->num < tempi&&lvs[i]->num!=-1)
		{
			tempi = lvs[i]->num;
			flagi = i;
		}
	}
	for (j = 0; j < 7; j++)
	{
		if (lvs[j]!=NULL&&lvs[j]->num < tempj&&j!=flagi&&lvs[j]->num != -1)
		{
			tempj = lvs[j]->num;
			flagj = j;
		}
	}
	//这里记录树可以用链表 不过差不多
	node *now = new node();
	now->left = lvs[flagi];
	now->right = lvs[flagj];
	now->num = tempi + tempj;
	lvs[flagi] = now;
	lvs[flagj] = NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	int flag = 6;
	while (flag--)
	{
		findMin();
	}
	return 0;
}


