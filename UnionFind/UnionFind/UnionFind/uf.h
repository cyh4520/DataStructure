#ifndef UF_H
#include<iostream>
using namespace std;
class uf
{
private:
	//组的个数
	int count;
	//以数组形式存储数据
	int *id;
	//数组的长度
	int length;
public:
	uf(int N)
	{
		count = N;
		length = N;
		id = new int[N];
		for (int i = 0; i < N; i++)
			id[i] = i;//开始时每个数字的组号即下标
	}
	//查找这个点所在的组号
	int Find(int p)
	{
		//根节点具有id[root]=root的性质
		if (p != id[p])
		return Find(id[p]);
		return p;
	}
	//联通这两个点
	void Union(int p, int q)
	{
		//如果没有联通
		if (!Connection(p, q))
		{
			int pId = Find(p);
			int qId = Find(q);
			/*for (int i = 0; i < length;i++)
			if (id[i] == pId)
				id[i] = qId;*/
			id[pId] = qId;
			count--;
		}
		
	}
	//查询这两个点是否已联通
	bool Connection(int p, int q)
	{
		return Find(p) == Find(q);
	}
	int Count()
	{
		return count;
	}
	void show()
	{
		for (int i = 0; i < length; i++)
			cout << id[i] << " ";
		cout << endl;
	}
};
#endif