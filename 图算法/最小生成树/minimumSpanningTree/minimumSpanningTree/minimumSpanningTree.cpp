// minimumSpanningTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>
#include<queue>
using namespace std;
#define inf 1000
int graph[7][7]=
{
	{ 0, 2, 4, 1, inf, inf, inf },
	{ 2, 0, inf, 3, 10, inf, inf },
	{ 4, inf, 0, 2, inf, 5, inf },
	{ 1, 3, 2, 0, 7, 8, 4 },
	{ inf, 10, inf, 7, 0, inf, 6 },
	{ inf, inf, 5, 8, inf, 0, 1 },
	{ inf, inf, inf, 4, 6, 1, 0 }
};
//记录是否访问过
int visit[7] = { 0 };
//记录此结点的父结点
int path[7] = { -1 };
int dist[7] = { inf };
void Prime();
void Kruskal();
int _tmain(int argc, _TCHAR* argv[])
{
    /*Prime();
	for (int i = 0; i < 7; i++)
		printf("%d\n",dist[i]);
	for (int i = 0; i < 7; i++)
		printf("%d\n", path[i]+1);*/
	Kruskal();
	system("pause");
	return 0;
}
//算法和dijstra差不多
//算法书上 P237页上的图其实有点误导
//每次出队列的顶点，只要是这个顶点能到的，都先算上距离，而不是直接找一个距离最短的
//然后再下一个顶点继续算能及的距离，如果没访问过的，直接算上距离，如果访问过的，那就比较一下看哪个近，需不需要更新dist
//采用的其实就是贪婪策略
void Prime()
{
	dist[0] = 0;
	int i = 0;
	int flag;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		i = q.front();
		q.pop();
		visit[i] = 1;
		for (int j = 0; j<7; j++)
		{
			//这个点符合条件没有被访问过
			if (graph[i][j] != 0 && graph[i][j] != inf&&visit[j] != 1)
			{
				dist[j] = graph[i][j];
				visit[j] = 1;
				path[j] = i;
				q.push(j);
			}
			//这个点符号条件但是被访问过，看要不要更新权值
			//事实上，这个更新比dijstra还简单一些，因为dijstra还需要加上之前路径的值，这个只需要记录局部值就可以
			if (graph[i][j] != 0 && graph[i][j] != inf&&visit[j] == 1)
			{
				if (dist[j] > graph[i][j])
				{
					dist[j] = graph[i][j];
					path[j] = i;
				}
			}
		}
	}
}


//这里顺便写下Union/Find算法
//维护一个UnionFindSet
int ufset[7] = { 0 };
void init()
{
	for (int i = 0; i < 7; i++)
		ufset[i] = i;
	//初始化时，他们的父节点就是自己
}
//找x的父节点
int Find(int x)
{
	//父节点就是自己
	if (ufset[x] == x)
		return x;
	else
		//如果是路径压缩的话可以用下面注释的代码这样 ,也就是多迭代一次，找自己父亲的父节点，这样的话可以减少树的深度
		// https://www.jianshu.com/p/b5b8d488266e
	/*{
	//此时找到x
		int result = Find(ufset[x]);
			ufset[x] = result;
			return result;
	}*/
		return Find(ufset[x]);
}
//合并两棵树
void Union(int x,int y)
{
	int root_x = Find(x);
	int root_y = Find(y);
	//本是同根生
	if (root_x == root_y)
		return;
	//合并根
	ufset[root_y] = root_x;
}
bool isCon(int x, int y)
{
	if (Find(x) == Find(y))
		return true;
	return false;
}
//q1:如何找到最短的边？
//q2:并且知道这条边对应的两个顶点？
//q3:终止条件是什么？
//在算法书的p239的解决方法是根据graph建立一个最小堆，将边排序，每次拿出一条边用deleteMin
//我这里先直接用另外一个邻接矩阵代替一下
//边长 顶点1 顶点2
int edge[12][3]=
{
	{ 1, 0, 3 },
	{ 1, 5, 6 },
	{ 2, 0, 1 },
	{ 2, 2, 3 },
	{ 3, 1, 3 },
	{ 4, 0, 2 },
	{ 4, 3, 6 },
	{ 5, 2, 5 },
	{ 6, 4, 6 },
	{ 7, 3, 4 },
	{ 8, 3, 5 },
	{ 10, 1, 4 }
};
void Kruskal()
{
	//初始化unionFindSet
	init();
	int edgeAccpt = 0;
	//定点数
	int vertexNum = 7;
	int i = 0;
	int e;
	int x, y,xroot,yroot;
	while (edgeAccpt < vertexNum - 1)
	{
		x = edge[i][1];
		y = edge[i][2];
		xroot = Find(x);
		yroot = Find(y);
		if (xroot != yroot)
		{
			edgeAccpt++;
			path[x] = y;

			Union(xroot, yroot);
		}
		i++;
	}
	//这个其实记录点不是特别方便
	//因为unionFind只能判断是否联通，它的那个集合记录的父结点用在这里有点问题
	//p239页中，第4步到第5步，2 4的父节点都是1，而此时要加入3，会把3的父节点直接设置为1，所以它这个UnionFindSet集合记录的只是一种关系。具体路径其实没有关系
	//比如UnionFind中可以压缩路径，即使树变得比较平，所以此时记录的只是是否联通的状态，路径可以更改，不太适用于这里输出
	//直接输出边比较方便
	for (int j = 0; j < i;j++)
	printf("%d %d\n", edge[j][1]+1,edge[j][2]+1);
	
}

