// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<memory>
#include<queue>
using namespace std;
#define inf 1000
#define min(x,y)((x) > (y)) ? (y) : (x)	

int Edmond_Karp(int s, int t);
int _tmain(int argc, _TCHAR* argv[])
{
	int flow = Edmond_Karp(0, 5);
	printf("%d", flow);
	system("pause");
	return 0;
}
//利用残余图实现
int graph[6][6] = 
{
	{ 0, 3, 2, inf, inf, inf },
	{ inf, 0, 1, 3, 4, inf },
	{ inf, inf, 0, inf, 2, inf },
	{ inf, inf, inf, 0, inf, 2 },
	{ inf, inf, inf, inf, 0, 3 },
	{ inf, inf, inf, inf, inf, 0 }
};
int pre[6] = { 0 };//记录结点i的前向结点为pre[i]
int resi[6][6] = { 0 };
int visit[6] = {0};//记录结点i是否被访问
//初始时now和grap图相同
int now[6][6] =
{
	{ 0, 3, 2, inf, inf, inf },
	{ inf, 0, 1, 3, 4, inf },
	{ inf, inf, 0, inf, 2, inf },
	{ inf, inf, inf, 0, inf, 2 },
	{ inf, inf, inf, inf, 0, 3 },
	{ inf, inf, inf, inf, inf, 0 }
};
//最大流算法的核心：引入反向边
// http://blog.csdn.net/x_y_q_/article/details/51999466
//Edmond—Karp算法
bool BFS(int s, int t)
{
	//每次调用BFS都初始化pre和visit，因为相当于是在新的图上进行广度搜索
	memset(pre, 0, sizeof(pre));
	memset(visit, 0, sizeof(visit));
	queue<int> que;
	que.push(s);
	visit[s] = 1;
	int p;
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		for (int i = 0; i < 6; i++)
		{
			//这个点（不是自己）可达并且没有被访问过
			if (graph[p][i] != 0 && graph[p][i] != inf&&visit[i] != 1)
			{
				pre[i] = p;
				visit[i] = 1;
				//找到了一条增广路径
				if (i == t)
					return true;
				que.push(i);
			}
		}
	}
	return false;
}
bool DFS(int s, int t)
{
	if (s == t) return true;
	bool flag = false;
	//用DFS的话得把pre和visit的每次初始化都放在Edmond_Karp这个函数里
	//用BFS的话不需要，因为BFS不是递归结构，DFS是递归结构，每次递归到这里要是把数组初始化的话就不行了
	/*memset(pre, 0, sizeof(pre));
	memset(visit, 0, sizeof(visit));*/
	for (int i = 0; i < 6; i++)
	{
		if (graph[s][i] != 0 && graph[s][i] != inf&&visit[i] != 1)
		{
			pre[i] = s;
			visit[i] = 1;
			flag=DFS(i, t);
			if (flag == false)
			{
				pre[i] = 0;
				visit[i] = 0;
			}
			//这里之前没加判断，这样的话弹栈的时候即使上一轮flag==true了，但是这里没有return true的操作的话，也会直接按顺序执行，直到最后的return false
			else
				return true;

		}
	}
	return false;
}
int Edmond_Karp(int s,int t)
{
	int maxflow = 0, d;
	//visit[s] DFS在这初始化， BFS可删除
	visit[s] = 1;
	while (DFS(s, t))
	{
		d = inf;
		for (int i = t; i != s; i = pre[i])
			//找到这条增广路径的最大流量
			d = min(d, graph[pre[i]][i]);
		for (int i = t; i != s; i = pre[i])
		{
			graph[pre[i]][i] -= d;
			graph[i][pre[i]] += d;
		}
		maxflow += d;
		//DFS需在这初始化,BFS可删除
		memset(pre, 0, sizeof(pre));
		memset(visit, 0, sizeof(visit));
	}
	return maxflow;
}


