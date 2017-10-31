// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<iostream>
#include"BST.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	BST bs;
	node t = new struct treeNode();
	node temp = new struct treeNode();
	t->value = 6;
	bs.init(t);

	bs.insert(t, 2);
	bs.insert(t, 8);
	bs.insert(t, 1);
	bs.insert(t, 4);
	bs.insert(t, 3);
	bs.insert(t, 5);
	bs.show(t);
	cout << endl;
	bs.Delete(t, 4);
	bs.show(t);
	//
	system("pause");
	return 0;
}

