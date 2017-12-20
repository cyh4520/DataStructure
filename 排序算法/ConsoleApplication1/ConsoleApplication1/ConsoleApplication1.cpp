// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
void show(int a[], int size);
void bubble(int a[], int size);
void selection_sort(int a[], int size); 
void insert_sort(int a[], int size);
void shell_sort(int a[], int size);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 10, 2, 7, 5, 6, 1, 3, 4, 8, 9 };
	int size = 10;

	shell_sort(a, size);
	show(a, size);
	system("pause");
	return 0;
}
//ð������
void bubble(int a[], int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		//�ڶ���ѭ����������һ��ʱ��˼��
		for (int j = 0; j < size-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
//ѡ������
void selection_sort(int a[], int size)
{
	int min = 0;
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		min= i;//ֱ�Ӽ�¼�±��λ��
		for (int j = i + 1; j < size;j++)
		if (a[j] < a[min])
			min = j;//ֱ�Ӹ����±��λ��
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
//��������
void insert_sort(int a[], int size)
{
	int i = 0,j;
	//����Ľ��޴��ˣ�֮ǰ��size ʵ��Ӧ����size-1,��Ϊ����Ҫ����һ��������ΪKEY����j=i+1,j��ΪKEY���±꣬�����size�Ļ����ͻ�Խ���������
	for (i = 0; i < size-1; i++)
	{
		//j Ҫ����������±�
		j = i + 1;
		int key = a[j];
		// last ������õ����е����һ�������±�
		int last = i;
		while (key<a[last]&&last>=0)
		{
			a[last + 1] = a[last];
			last--;
		}
		a[last + 1] = key;
	}
}
//ϣ������
void shell_sort(int a[], int size)
{
	int incre = size / 2;
	int i = 0;
	int last=0,reallast=0, num, j, key;
	while (true)
	{
		//�任������ͬʱ��last���±�Ҳ���»���
		if (reallast >= incre)
		{
			reallast = 0;
			//��ֹ��������������
			incre /= 2;
			if (incre == 0) break;
		}
		//reallast������ͬ�����²�ͬ��������������һ��ֵ
		//���� 10 2 7 5 6 1 3 4 8 9
		//��һ������Ϊ5 reallast �ֱ�Ϊ10 2 7 5 6
		last = reallast;
		//last���Ƶ���ÿ����ѡ�������е�����������һ��ֵ��������൱��ѡ��һ�������������в�������
		//j���Ƶ�����ѡ�������е�δ����ĵ�һ��ֵ������j=last+incre
		
		//k���Ƶ���ѭ����������Ϊÿ�ζ�Ҫ����ȡһ������Ϊδ���������������ֹ������size-incre������size
		for (int k = 0; k < size - incre; k += incre){
			//����������һ����ֵs
			//last += k;
			num = a[last];
			//δ����ĵ�һ�����±�
			j = last+incre;
			//δ����ĵ�һ����ֵ
			key = a[j];
			//ֵ��ע����ǣ���ÿ�β�������������Ƹ�ֵʱ��last��ֵ��ı䣬���������Ҫ���¸�last��ֵ����Ϊ��ʱ���Ѿ���δ�������Ҳ������������
			//���Դ�ʱֱ�ӽ�j��ֵ����δ����ĵ�һ���±꣩����last����
			while (key < a[last] && last >= 0)
			{
				a[last + incre] = a[last];
				last -= incre;
			}

			a[last + incre] = key;
			last = j;
		}
		//ÿ��ͬһ������һ����ѡ���Ժ��ȡ��һ����
		reallast++;
	}
}
//�������
void show(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

