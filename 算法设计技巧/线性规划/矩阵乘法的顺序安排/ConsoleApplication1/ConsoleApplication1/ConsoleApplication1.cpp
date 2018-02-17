// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<Windows.h>
#define N 4
#define infinite 100000
typedef struct Matrix
{
	//��
	int row;
	//��
	int col;
}mat;

mat matrix[N];
void init()
{
	matrix[0].row = 50;
	matrix[0].col = 10;

	matrix[1].row = 10;
	matrix[1].col = 40;

	matrix[2].row = 40;
	matrix[2].col = 30;

	matrix[3].row = 30;
	matrix[3].col = 5;
}
//matrix[index]����
int C(int index)
{
	if (index == -1) return matrix[0].row;
	else
		return matrix[index].col;
}
int func(int left, int right)
{
	int min = infinite;
	int num;
	if (left == right) return 0;
	for (int i = left; i < right; i++)
	{
		//                                        left���У�left-1���о���left���У���Ȼ�޷����㣩*i����*right����
		num = func(left, i) + func(i + 1, right) + C(left - 1)*C(i)*C(right);
		if (num < min)
			min = num;
	}
	return min;
}
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	int min=func(0, 3);
	printf("%d ", min);
	system("pause");
	return 0;
}

