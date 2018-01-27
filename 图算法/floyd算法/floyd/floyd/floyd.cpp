// floyd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<Windows.h>
#define inf 1000
//dijkstra算法是实现单源最短距离
//floyd算法是实现多源最短距离
//若有N个顶点，更新N次就可算出所有点对的最短距离
//数据结构还是为邻接矩阵
int dist[7][7]=
{
	{inf,12,inf,inf,inf,16,14},
	{12,inf,10,inf,inf,7,inf},
	{inf,10,inf,3,5,6,inf},
	{ inf, inf, 3, inf, 4 ,inf,inf},
	{inf,inf,5,4,inf,2,8},
	{16,7,6,inf,2,inf,9},
	{14,inf,inf,inf,8,9,inf}
};
int path[7][7] = { 0 };
void init();
void floyd();
void show();
void showPath();
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	floyd();
	show();
	showPath();
	system("pause");
	return 0;
}
void init()
{
	int i,j;
	for (i = 0; i < 7;i++)
	for (j = 0; j < 7; j++)
	{
		path[i][j] = j;
	}
}
//其实floyd的图的组织我感觉是需要有一点约束的
//就是编号的时候，编的时候必须连续的号码能由一条线连起来。
//假设我此时的4号变成了2，相当于1对于2就是不可达的状态了，因为经过一个点都不可达2
//图在 http://blog.csdn.net/qq_35644234/article/details/60875818
//如果连续的话，按照for循环可以一步一步地找跳板，即此时要找到4，我至少要经过一个点，此时这个点可以是3，因为按顺序连接，我此时3肯定可以能到了
//相当于直接以3这个点为跳板可以到4，假设我2 4互换，当1到2的跳板此时只有4 6 7都不可达2，所以这时候1对于2就是不可达状态了。
void floyd()
{
	int i = 0,j=0, k = 0;
	//更新N次（顶点数）就可完成
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (i != j){
				for (k = 0; k < 7; k++)
				{
					//如果当前路径大于经过k顶点的路程，则更新路程
					//动态规划 背包问题
					if (dist[i][j]>(dist[i][k] + dist[k][j]))
					{
						dist[i][j]=(dist[i][k] + dist[k][j]);
						path[i][j] = path[i][k];
					}
				}
			}
		}
	}

}
void show()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}
void showPath()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (i != j)
			{
				printf("V%d to V%d path is: ", i, j);
				int temp;
				printf("V%d-->", i);
				temp = path[i][j];
				while (temp != j)
				{
					printf("V%d-->", temp);
					temp = path[temp][j];
				}
				printf("V%d\n", j);
			}
		}
		printf("\n");
	}
}

