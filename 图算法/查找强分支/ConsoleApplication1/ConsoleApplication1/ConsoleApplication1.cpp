// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<Windows.h>
#define N 10
int graph[10][10]=
{
	{ 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }

};
int visit[N] = { 0 };
int num[N] = { 0 };
int sum = 1;
int strongCon[N][N];
int row;
int rank;
void assignNum(int u)
{
	visit[u] = 1;
	for (int i = 0; i < N; i++)
	{
		if (i != u&&graph[u][i] && visit[i] != 1)
		{
			assignNum(i);
		}
	}
	num[u] = sum++;
}
void assignAll()
{
	for (int i = 0; i < N; i++)
	{
		if (visit[i] != 1)
		{
			assignNum(i);
		}
	}
}
//��ת
void invert()
{
	/*������ô�ı��ͷ�����������*/
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j])
			{
				graph[j][i] = 1;
				graph[i][j] = 0;
			}
		}
	}
	*/
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (graph[i][j])
			{
				graph[j][i] = 1;
				graph[i][j] = 0;
			}
			else if (graph[j][i])
			{
				graph[j][i] = 0;
				graph[i][j] = 1;
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}
void dfs(int u)
{
	visit[u] = 1;
	strongCon[row][rank++] = u+1;
	for (int i = 0; i < N; i++)
	{
		if (u != i&&graph[u][i] && visit[i] != 1)
		{
			dfs(i);
		}
	}
}
void findStrong()
{
	int j = 0;
	for (int i = N; i >= 1; i--)
	{
		for (j = 0; j < N; j++)
		{
			if (num[j] == i)
			{
				//û�б����ʹ�
				if (visit[j] != 1)
				{
					dfs(j);
					break;
				}
			}
		}
		row++;
		rank = 0;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	assignAll();
	invert();
	findStrong();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", strongCon[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

