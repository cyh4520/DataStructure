// graph.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include<memory.h>
#include<queue>
using namespace std;
#define infinite 10000
//������Դ�����ݽṹ���㷨 p220��ͼ
//�ö�ά��������ʾͼ
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
	//˵����1�Ѿ����ʹ���
	visited[0] = 1;
	//breadth_first_search(0, 5,0);

	//printf("%d", min);
	Dijkstra(0);
	system("pause");
	return 0;
}
//Ū�˺þã�֮ǰ��Ūlent���飬��ʱ����ǰ�ÿ��·�ĳ��ȶ���¼���������ǻ���һ�������������¼��ʽ��������ĳ���㣬�����������
//�ҿ�ʼ���ˣ����ǻ����Ժ�Ҫ��ʼ��¼��һ��·�ˣ�������Ļ����İ�ǰ�������һЩ�����ƹ�������֮��̫�ò���
//ֱ���������������� len�����������¼��ǰ�Ѿ��߹���·�������Ļ�ÿ�δ��ζ���ֱ��֪����ǰ�Ѿ����˶���·��
//��������ȱ����ĵݹ鷽��ʵ�֣�����Ƿǵݹ�����Ҫ�õ�ջ,Ҳ�ɲ��ù�����ȱ����ķǵݹ鷽��ʵ�֣������ö��У�
int breadth_first_search(int start, int dest,int len)
{
	int i = 0;
	//����������յ�˵���ҵ���
	if (start == dest) { 
		if (mi > len)
			mi = len;
		return 0;
	}
	//������ǵĻ�������Χÿ�����ߵĵ㣬�������Լ��Ͳ��������ĵ�
	for (i = 0; i < 7; i++)
	{
		//�������������ĵ�,����û�б����ʹ�
		if (graph[start][i] != infinite&&graph[start][i]!=0&&visited[i]!=1)
		{
			//��˵������·�����У����Ҽ��뵽·��������
			//ͬʱ�������Ϊ����������
			visited[i] = 1;
			breadth_first_search(i, dest, len + graph[start][i]);
			visited[i] = 0;
		}
	}
	return 0;
}

int path[7] = { 0 };
//������Գ�ʼ��ʱ��Ϊ0�����ǲ�����Ϊһ����0�����֣����������ʼ����ֵdist���˵�һ��ֵΪinfinite�⣬����ȫ��0
//�����ʼ���б��е�Ԫ�ظ���С��ָ�������鳤��ʱ�������Ԫ�ز���Ĭ��ֵ��������ֻ���Ĭ��ֵ0
//����memset��ֵ��ʱ��
int dist[7] = { infinite };
//dijkstra�㷨
//̰���㷨��һ������
//��ÿ�׶ζ���������õ�ȥ����
void Dijkstra(int start)
{
	//��Ϊmemset�����ֽ�Ϊ��λ���Ƕ�arrayָ����ڴ��4���ֽڣ�������ֽ����ǰ�sizeof(int)����ģ����и�ֵ����������ֱ�Ӹ�ֵҲ�����
	//��Ϊ���ֽ�Ϊ��λ����ÿ���ֽڸ���ֵΪ10000��һ��int��Ԫ����ֵ�ͱ������������
	//һ����λ����ֵ�൱����00010000 00010000 00010000 00010000 
	//��0ʱû�����⣬��Ϊһ����λ����ֵ�൱����00000000 00000000 00000000 00000000 ����0
	memset(dist, infinite, sizeof(int)*7);
	for (int i = 0; i < 7; i++)
		dist[i] = infinite;
	dist[start] = 0; visited[0] = 1;
	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{
		//�ó����Ԫ��
		int temp = Q.front();
		//������Ϊ���ʹ���
		//��������Ϊ���ʹ���̫�ã�������1�ӷ��ʱȽϺ�
		//visited[temp] = 1;
		for (int i = 0; i < 7; i++)
		{
			//�����û���ʹ�
			//��©��û�мӵ��жϣ�������ǲ����Լ������Լ�Ҳ��������
			if (graph[temp][i] != infinite&&temp != i&&visited[i] != 1)
			{
				Q.push(i);
				//1 ���뼴����
				//�����������ͷ��ʵĻ������push���Ѿ��ڶ����ﵫ�ǻ�û�ó����ĵ㣬�����ظ������г���
				����
				visited[i] = 1;
				dist[i] = dist[temp] + graph[temp][i];
				path[i] = temp;
			}
			//�������ʹ��ˣ����費��Ҫ����Ȩֵ
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
