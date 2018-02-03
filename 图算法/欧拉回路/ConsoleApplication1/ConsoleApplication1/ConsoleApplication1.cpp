// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<queue>
#include<stack>
using namespace std;
#define N 12

//�ڽӱ�
int node[N][N]=
{
	{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1 },
	{ 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 }
};
struct Node
{
	int x;
	int y;
};
//����û�б����ʹ�
int visit[N][N] = { 0 };
queue<int> point;
queue<int> back;
stack<int> sta;
int sum;
void dfs(int u)
{
	int i;
	sta.push(u);
	for (i = 0; i < N; i++)
	{
		//�����ߴ��ڣ�����û�б����ʹ�
		if (node[u][i] && visit[u][i] != 1)
		{
			visit[u][i] = 1;
			visit[i][u] = 1;
			//point.push(i);
			sum++;
			//�е���߾�break;
			dfs(i);
			break;
		}
	}
	//����������еı߶������ˣ��Ǿͻ���
	if (i == N)
	{
		if (sum == 21) return;
		back.push(sta.top());//���ݵĵ����
		sta.pop();
		int top = sta.top();
		sta.pop();
		dfs(top);
	}
		
}
//�ڶ��ַ����Ƚ����ֱ�Ӽ�¼����·����Ϊ·����ֱ����ջ��������Ϊֹ
//��ʵ�͵�һ��Ҳ���
void dfs2(int u)
{
	sta.push(u);
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (node[u][i] && visit[u][i] != 1)
		{
			visit[u][i] = 1;
			visit[i][u] = 1;
			dfs2(i);
			break;
		}
	}
	//��Ҫ������
	if (i == N)
	{
		printf("%d ", u+1);
		sta.pop();
		if (sta.empty()) return;
		int top = sta.top();
		sta.pop();
		dfs2(top);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*dfs(4);
	stack<int> prin;
	while (!sta.empty())
	{
		prin.push(sta.top());
		sta.pop();
	}
	while (!prin.empty())
	{
		printf("%d ", prin.top() + 1);
		prin.pop();
	}
	while (!back.empty())
	{
		printf("%d ", back.front()+1);
		back.pop();
	}*/
	dfs2(4);
	system("pause");
	return 0;
}

