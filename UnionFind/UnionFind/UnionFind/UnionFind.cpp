// UnionFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"uf.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10;
	uf u(n);
	/*u.Union(0, 1);
	u.Union(2, 1);
	u.Union(5, 0);
	u.Union(6, 5);
	u.Union(7, 1);
	u.Union(3, 8);
	u.Union(4, 3);
	u.Union(9, 8);
	u.show();
	u.Union(5, 9);
	u.show();*/
	u.Union(0, 1);
	u.Union(0, 2);
	u.Union(0, 3);
	u.Union(0, 4);
	u.Union(0, 5);
	u.show();
	system("pause");
	return 0;
}

