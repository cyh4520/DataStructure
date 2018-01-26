// graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;
#define infinite 10000
//数据来源于数据结构与算法 p220的图
//用二维数组来表示图
int lenth[36] = { 0 };
int length_index = 0;
int graph[7][7] = {
	{ 0, 2, infinite, 1, infinite, infinite, infinite },
	{ infinite, 0, infinite, 3, 10, infinite, infinite },
	{ 4, infinite, 0, 2, infinite, 5, infinite },
	{ infinite, infinite, 2, 0, 2, 8, 4 },
	{ infinite, infinite, infinite, infinite, 0, infinite, 6 },
	{infinite, infinite, infinite, infinite, infinite, 0, infinite},
	{infinite, infinite, infinite, infinite, infinite, 1, 0}
};
int  mi = 999;
int visited[7] = { 0 };
int breadth_first_search(int start, int dest,int len);
void Dijkstra(int start);
int _tmain(int argc, _TCHAR* argv[])
{
	//说明点1已经访问过了
	visited[0] = 1;
	//breadth_first_search(0, 5,0);

	//printf("%d", min);
	Dijkstra(0);
	system("pause");
	return 0;
}
//弄了好久，之前还弄lent数组，当时想的是把每条路的长度都记录下来，但是会有一个问题我这个记录方式，即到了某个点，这个点走完了
//我开始回退，但是回退以后要开始记录下一条路了，用数组的话还的把前面走完的一些给复制过来，总之不太好操作
//直接在这个函数里加了 len这个变量，记录当前已经走过的路，这样的话每次传参都能直接知道当前已经走了多少路了
//用深度优先遍历的递归方法实现，如果是非递归则需要用到栈,也可采用广度优先遍历的非递归方法实现（即利用队列）
int breadth_first_search(int start, int dest,int len)
{
	int i = 0;
	//如果起点就是终点说明找到了
	if (start == dest) { 
		if (mi > len)
			mi = len;
		return 0;
	}
	//如果不是的话则走周围每个能走的点，即不是自己和不是无穷大的点
	for (i = 0; i < 7; i++)
	{
		//如果身边有这样的点,并且没有被访问过
		if (graph[start][i] != infinite&&graph[start][i]!=0&&visited[i]!=1)
		{
			//那说明这条路径可行，并且加入到路径数组中
			//同时以这个点为起点继续搜索
			visited[i] = 1;
			breadth_first_search(i, dest, len + graph[start][i]);
			visited[i] = 0;
		}
	}
	return 0;
}

int path[7] = { 0 };
//数组可以初始化时都为0，但是不可以为一个非0的数字，下面这个初始化的值dist除了第一个值为infinite外，后面全是0
//数组初始化列表中的元素个数小于指定的数组长度时，不足的元素补以默认值。即这里只会填补默认值0
//可用memset赋值这时候
int dist[7] = { infinite };
//dijkstra算法
//贪婪算法的一个例子
//把每阶段都当做是最好的去处理
void Dijkstra(int start)
{
	//因为memset是以字节为单位就是对array指向的内存的4个字节（这里的字节数是按sizeof(int)计算的）进行赋值，下面这样直接赋值也会出错
	//因为以字节为单位，那每个字节赋的值为10000，一个int单元赋的值就变成了下面这样
	//一个单位赋的值相当于是00010000 00010000 00010000 00010000 
	//赋0时没有问题，因为一个单位赋的值相当于是00000000 00000000 00000000 00000000 还是0
	memset(dist, infinite, sizeof(int)*7);
	for (int i = 0; i < 7; i++)
		dist[i] = infinite;
	dist[start] = 0; visited[0] = 1;
	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{
		//拿出这个元素
		int temp = Q.front();
		//并且置为访问过了
		//在这里标记为访问过不太好，在下面1加访问比较好
		//visited[temp] = 1;
		for (int i = 0; i < 7; i++)
		{
			//这个点没访问过
			//疏漏：没有加的判断：这个点是不是自己，是自己也不用走了
			if (graph[temp][i] != infinite&&temp != i&&visited[i] != 1)
			{
				Q.push(i);
				//1 推入即访问
				//如果是在上面就访问的话这里会push进已经在队列里但是还没拿出来的点，容易重复进队列出现
				错误
				visited[i] = 1;
				dist[i] = dist[temp] + graph[temp][i];
				path[i] = temp;
			}
			//这个点访问过了，看需不需要更新权值
			if (graph[temp][i] != infinite&&temp != i&&visited[i] == 1)
			{
				int now = dist[temp] + graph[temp][i];
				if (now < dist[i])
				{
					dist[i] = now;
					path[i] = temp;
				}
			}
		}
		Q.pop();
	}
	for (int i = 0; i < 7; i++)
		printf("%d\n", dist[i]);
}
