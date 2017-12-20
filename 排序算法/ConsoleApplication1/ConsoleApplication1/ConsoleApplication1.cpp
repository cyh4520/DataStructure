// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
//冒泡排序
void bubble(int a[], int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		//第二层循环这里用了一点时间思考
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
//选择排序
void selection_sort(int a[], int size)
{
	int min = 0;
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		min= i;//直接记录下标的位置
		for (int j = i + 1; j < size;j++)
		if (a[j] < a[min])
			min = j;//直接更改下标的位置
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
//插入排序
void insert_sort(int a[], int size)
{
	int i = 0,j;
	//这里的界限错了，之前是size 实际应该是size-1,因为至少要留出一个数来作为KEY，即j=i+1,j即为KEY的下标，如果是size的话，就会越界出现问题
	for (i = 0; i < size-1; i++)
	{
		//j 要插入的数的下标
		j = i + 1;
		int key = a[j];
		// last 已排序好的序列的最后一个数的下标
		int last = i;
		while (key<a[last]&&last>=0)
		{
			a[last + 1] = a[last];
			last--;
		}
		a[last + 1] = key;
	}
}
//希尔排序
void shell_sort(int a[], int size)
{
	int incre = size / 2;
	int i = 0;
	int last=0,reallast=0, num, j, key;
	while (true)
	{
		//变换增量的同时把last的下标也重新换过
		if (reallast >= incre)
		{
			reallast = 0;
			//终止条件设置在这里
			incre /= 2;
			if (incre == 0) break;
		}
		//reallast控制相同增量下不同数的已排序的最后一个值
		//例如 10 2 7 5 6 1 3 4 8 9
		//第一趟增量为5 reallast 分别为10 2 7 5 6
		last = reallast;
		//last控制的是每次挑选出的数列的已排序的最后一个值。这个就相当于选择一部分数出来进行插入排序
		//j控制的是挑选出的数列的未排序的第一个值，所以j=last+incre
		
		//k控制的是循环次数，因为每次都要向后多取一个数作为未排序的数，所以终止条件是size-incre而不是size
		for (int k = 0; k < size - incre; k += incre){
			//已排序的最后一个的值s
			//last += k;
			num = a[last];
			//未排序的第一个的下标
			j = last+incre;
			//未排序的第一个的值
			key = a[j];
			//值得注意的是，在每次插入排序向后推移赋值时，last的值会改变，所以在最后要重新给last赋值，因为这时候已经将未排序的数也排入数列中了
			//所以此时直接将j的值（即未排序的第一个下标）赋给last即可
			while (key < a[last] && last >= 0)
			{
				a[last + incre] = a[last];
				last -= incre;
			}

			a[last + incre] = key;
			last = j;
		}
		//每次同一增量下一个数选完以后就取下一个数
		reallast++;
	}
}
//输出函数
void show(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

