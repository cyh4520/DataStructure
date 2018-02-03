// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<queue>
#include<stack>
using namespace std;
#define N 12

//邻接表
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
//边有没有被访问过
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
		//这条边存在，并且没有被访问过
		if (node[u][i] && visit[u][i] != 1)
		{
			visit[u][i] = 1;
			visit[i][u] = 1;
			//point.push(i);
			sum++;
			//有点可走就break;
			dfs(i);
			break;
		}
	}
	//如果找了所有的边都不行了，那就回溯
	if (i == N)
	{
		if (sum == 21) return;
		back.push(sta.top());//回溯的点加入
		sta.pop();
		int top = sta.top();
		sta.pop();
		dfs(top);
	}
		
}
//第二种方法比较巧妙，直接记录回溯路径作为路径，直到把栈都回溯完为止
//其实和第一种也差不多
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
	//需要回溯了
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

