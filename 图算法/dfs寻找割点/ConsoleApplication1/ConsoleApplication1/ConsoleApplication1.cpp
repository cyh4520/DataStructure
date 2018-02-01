// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<Windows.h>
#define min(x,y)((x)>(y)?(y):(x))
//1Ϊ�ɵ���
int graph[7][7] = 
{
	{ 1, 1, 0, 1, 0, 0, 0 },
	{ 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 0, 0, 1 }
};

int visit[7] = { 0 };
int num[7] = { 0 };
int low[7] = { 0 };
int parent[7] = { 0 };
int count=1;
int vis[7] = { 0 };
void init()
{
	for (int i = 0; i < 7; i++)
		parent[i] = i;
}
//�������һ�����Num����
void assignNum(int vertex)
{
	num[vertex] = count++;
	visit[vertex] = 1;
	for (int i = 0; i < 7; i++)
	{
		//����㲻���Լ���û�б����ʹ�������vertex�ɴ�
		if (i != vertex&&visit[i] != 1 && graph[vertex][i] == 1)
		{
			parent[i] = vertex;
			assignNum(i);
		}
	}
}
//�жϸ��Ƿ�Ϊ��� ��������������ϵĶ������Ǹ�㣬������
bool isStart(int v)
{
	int flag = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i!=v&&parent[i] == v)
			flag++;
	}
	if (flag < 2)
		return false;
	else 
		return true;
}
void assignLow(int v)
{
	vis[v] = 1;
	//rule 1
	low[v] = num[v];
	for (int i = 0; i < 7; i++)
	{
		//����㲻���Լ����ҿɴ�
		if (i != v&&graph[v][i] == 1)
		{
			if (num[i]>num[v])//forward edge
			{
				if (vis[i]!=1)
				assignLow(i);
				if (low[i] >= num[v])
				{

					//����Ƕ���Ļ�
					if (num[v] == 1)
						if(isStart(v))
						printf("%d is an articulation point\n", v);
						else;
					else
						printf("%d is an articulation point\n", v);
				}
				low[v] = min(low[v], low[i]);//rule 3
			}
			else //back edge
			{
				if (parent[v] != i)
				{
					low[v] = min(low[v], num[i]);
				}
			}
		}
	}
}
void findArt(int v)
{
	vis[v] = 1;
	//rule 1
	num[v] = count++; //�������
	low[v] = num[v];
	visit[v] = 1;
	for (int i = 0; i < 7; i++)
	{
		//����㲻���Լ����ҿɴ�
		if (i != v&&graph[v][i] == 1)
		{
			if (visit[i]!=1)//forward edge �������
			{
				parent[i] = v;
				if (vis[i] != 1)
					findArt(i);
				if (low[i] >= num[v])
				{

					//����Ƕ���Ļ�
					if (num[v] == 1)
					if (isStart(v))
						printf("%d is an articulation point\n", v);
					else;
					else
						printf("%d is an articulation point\n", v);
				}
				low[v] = min(low[v], low[i]);//rule 3
			}
			else //back edge
			{
				if (parent[v] != i)
				{
					low[v] = min(low[v], num[i]);
				}
			}
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	/*assignNum(0);
	assignLow(0);*/
	findArt(0);
	system("pause");
	return 0;
}

