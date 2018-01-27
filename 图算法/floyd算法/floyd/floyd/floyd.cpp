// floyd.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<Windows.h>
#define inf 1000
//dijkstra�㷨��ʵ�ֵ�Դ��̾���
//floyd�㷨��ʵ�ֶ�Դ��̾���
//����N�����㣬����N�ξͿ�������е�Ե���̾���
//���ݽṹ����Ϊ�ڽӾ���
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
//��ʵfloyd��ͼ����֯�Ҹо�����Ҫ��һ��Լ����
//���Ǳ�ŵ�ʱ�򣬱��ʱ����������ĺ�������һ������������
//�����Ҵ�ʱ��4�ű����2���൱��1����2���ǲ��ɴ��״̬�ˣ���Ϊ����һ���㶼���ɴ�2
//ͼ�� http://blog.csdn.net/qq_35644234/article/details/60875818
//��������Ļ�������forѭ������һ��һ���������壬����ʱҪ�ҵ�4��������Ҫ����һ���㣬��ʱ����������3����Ϊ��˳�����ӣ��Ҵ�ʱ3�϶������ܵ���
//�൱��ֱ����3�����Ϊ������Ե�4��������2 4��������1��2�������ʱֻ��4 6 7�����ɴ�2��������ʱ��1����2���ǲ��ɴ�״̬�ˡ�
void floyd()
{
	int i = 0,j=0, k = 0;
	//����N�Σ����������Ϳ����
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (i != j){
				for (k = 0; k < 7; k++)
				{
					//�����ǰ·�����ھ���k�����·�̣������·��
					//��̬�滮 ��������
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

