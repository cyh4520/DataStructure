// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<memory>
double Eval(int N)
{
	int i, j;
	double sum, answer;
	double *C;
	C = (double*)malloc(sizeof(double)*(N + 1));
	if (C == NULL)
		return -1;
	C[0] = 1.0;
	double last = 0;
	last = C[0];
	//这里可以改成线性的
	//emmm 把递归用动态规划改为非线性，主要就是把状态写出来，画成一张表或者一张图，把哪些可以重复计算的给省略，可以大大提高运行效率 p289 就是画图解决
	for (int i = 1; i <= N; i++)
	{
		C[i] = 2.0*last / i + i;
		last += C[i];
	}
	answer = C[N];
	free(C);
	return answer;
}
int _tmain(int argc, _TCHAR* argv[])
{
	double answer=Eval(5);
	printf("%lf", answer);
	system("pause");
	return 0;
}

