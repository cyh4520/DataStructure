// Adelson-Velskii.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"AvlTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	node root = new struct treeNode();
	root->value = 1;
	AvlTree tree;
	tree.init(root);
	root=tree.insert(root, 3);
	root=tree.insert(root, 2);
	tree.show(root);
	system("pause");
	return 0;
}

