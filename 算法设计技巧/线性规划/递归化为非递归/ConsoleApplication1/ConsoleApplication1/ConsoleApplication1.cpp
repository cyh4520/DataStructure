// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//������Ըĳ����Ե�
	//emmm �ѵݹ��ö�̬�滮��Ϊ�����ԣ���Ҫ���ǰ�״̬д����������һ�ű����һ��ͼ������Щ�����ظ�����ĸ�ʡ�ԣ����Դ���������Ч�� p289 ���ǻ�ͼ���
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

