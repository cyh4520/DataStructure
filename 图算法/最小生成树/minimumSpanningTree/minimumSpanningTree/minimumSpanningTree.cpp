// minimumSpanningTree.cpp : �������̨Ӧ�ó������ڵ㡣
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
//��¼�Ƿ���ʹ�
int visit[7] = { 0 };
//��¼�˽��ĸ����
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
//�㷨��dijstra���
//�㷨���� P237ҳ�ϵ�ͼ��ʵ�е���
//ÿ�γ����еĶ��㣬ֻҪ����������ܵ��ģ��������Ͼ��룬������ֱ����һ��������̵�
//Ȼ������һ������������ܼ��ľ��룬���û���ʹ��ģ�ֱ�����Ͼ��룬������ʹ��ģ��ǾͱȽ�һ�¿��ĸ������費��Ҫ����dist
//���õ���ʵ����̰������
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
			//������������û�б����ʹ�
			if (graph[i][j] != 0 && graph[i][j] != inf&&visit[j] != 1)
			{
				dist[j] = graph[i][j];
				visit[j] = 1;
				path[j] = i;
				q.push(j);
			}
			//���������������Ǳ����ʹ�����Ҫ��Ҫ����Ȩֵ
			//��ʵ�ϣ�������±�dijstra����һЩ����Ϊdijstra����Ҫ����֮ǰ·����ֵ�����ֻ��Ҫ��¼�ֲ�ֵ�Ϳ���
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


//����˳��д��Union/Find�㷨
//ά��һ��UnionFindSet
int ufset[7] = { 0 };
void init()
{
	for (int i = 0; i < 7; i++)
		ufset[i] = i;
	//��ʼ��ʱ�����ǵĸ��ڵ�����Լ�
}
//��x�ĸ��ڵ�
int Find(int x)
{
	//���ڵ�����Լ�
	if (ufset[x] == x)
		return x;
	else
		//�����·��ѹ���Ļ�����������ע�͵Ĵ������� ,Ҳ���Ƕ����һ�Σ����Լ����׵ĸ��ڵ㣬�����Ļ����Լ����������
		// https://www.jianshu.com/p/b5b8d488266e
	/*{
	//��ʱ�ҵ�x
		int result = Find(ufset[x]);
			ufset[x] = result;
			return result;
	}*/
		return Find(ufset[x]);
}
//�ϲ�������
void Union(int x,int y)
{
	int root_x = Find(x);
	int root_y = Find(y);
	//����ͬ����
	if (root_x == root_y)
		return;
	//�ϲ���
	ufset[root_y] = root_x;
}
bool isCon(int x, int y)
{
	if (Find(x) == Find(y))
		return true;
	return false;
}
//q1:����ҵ���̵ıߣ�
//q2:����֪�������߶�Ӧ���������㣿
//q3:��ֹ������ʲô��
//���㷨���p239�Ľ�������Ǹ���graph����һ����С�ѣ���������ÿ���ó�һ������deleteMin
//��������ֱ��������һ���ڽӾ������һ��
//�߳� ����1 ����2
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
	//��ʼ��unionFindSet
	init();
	int edgeAccpt = 0;
	//������
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
	//�����ʵ��¼�㲻���ر𷽱�
	//��ΪunionFindֻ���ж��Ƿ���ͨ�������Ǹ����ϼ�¼�ĸ�������������е�����
	//p239ҳ�У���4������5����2 4�ĸ��ڵ㶼��1������ʱҪ����3�����3�ĸ��ڵ�ֱ������Ϊ1�����������UnionFindSet���ϼ�¼��ֻ��һ�ֹ�ϵ������·����ʵû�й�ϵ
	//����UnionFind�п���ѹ��·������ʹ����ñȽ�ƽ�����Դ�ʱ��¼��ֻ���Ƿ���ͨ��״̬��·�����Ը��ģ���̫�������������
	//ֱ������߱ȽϷ���
	for (int j = 0; j < i;j++)
	printf("%d %d\n", edge[j][1]+1,edge[j][2]+1);
	
}

