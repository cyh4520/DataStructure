// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
//���ò���ͼʵ��
int graph[6][6] = 
{
	{ 0, 3, 2, inf, inf, inf },
	{ inf, 0, 1, 3, 4, inf },
	{ inf, inf, 0, inf, 2, inf },
	{ inf, inf, inf, 0, inf, 2 },
	{ inf, inf, inf, inf, 0, 3 },
	{ inf, inf, inf, inf, inf, 0 }
};
int pre[6] = { 0 };//��¼���i��ǰ����Ϊpre[i]
int resi[6][6] = { 0 };
int visit[6] = {0};//��¼���i�Ƿ񱻷���
//��ʼʱnow��grapͼ��ͬ
int now[6][6] =
{
	{ 0, 3, 2, inf, inf, inf },
	{ inf, 0, 1, 3, 4, inf },
	{ inf, inf, 0, inf, 2, inf },
	{ inf, inf, inf, 0, inf, 2 },
	{ inf, inf, inf, inf, 0, 3 },
	{ inf, inf, inf, inf, inf, 0 }
};
//������㷨�ĺ��ģ����뷴���
// http://blog.csdn.net/x_y_q_/article/details/51999466
//Edmond��Karp�㷨
bool BFS(int s, int t)
{
	//ÿ�ε���BFS����ʼ��pre��visit����Ϊ�൱�������µ�ͼ�Ͻ��й������
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
			//����㣨�����Լ����ɴﲢ��û�б����ʹ�
			if (graph[p][i] != 0 && graph[p][i] != inf&&visit[i] != 1)
			{
				pre[i] = p;
				visit[i] = 1;
				//�ҵ���һ������·��
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
	//��DFS�Ļ��ð�pre��visit��ÿ�γ�ʼ��������Edmond_Karp���������
	//��BFS�Ļ�����Ҫ����ΪBFS���ǵݹ�ṹ��DFS�ǵݹ�ṹ��ÿ�εݹ鵽����Ҫ�ǰ������ʼ���Ļ��Ͳ�����
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
			//����֮ǰû���жϣ������Ļ���ջ��ʱ��ʹ��һ��flag==true�ˣ���������û��return true�Ĳ����Ļ���Ҳ��ֱ�Ӱ�˳��ִ�У�ֱ������return false
			else
				return true;

		}
	}
	return false;
}
int Edmond_Karp(int s,int t)
{
	int maxflow = 0, d;
	//visit[s] DFS�����ʼ���� BFS��ɾ��
	visit[s] = 1;
	while (DFS(s, t))
	{
		d = inf;
		for (int i = t; i != s; i = pre[i])
			//�ҵ���������·�����������
			d = min(d, graph[pre[i]][i]);
		for (int i = t; i != s; i = pre[i])
		{
			graph[pre[i]][i] -= d;
			graph[i][pre[i]] += d;
		}
		maxflow += d;
		//DFS�������ʼ��,BFS��ɾ��
		memset(pre, 0, sizeof(pre));
		memset(visit, 0, sizeof(visit));
	}
	return maxflow;
}


