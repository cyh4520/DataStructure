// UnionFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"uf.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10;
	uf u(n);
	u.Union(0, 1);
	u.Union(2, 1);
	u.Union(5, 1);
	u.Union(6, 1);
	u.Union(7, 1);
	u.Union(3, 8);
	u.Union(4, 8);
	u.Union(9, 8);
	u.show();
	u.Union(5, 9);
	u.show();
	system("pause");
	return 0;
}

