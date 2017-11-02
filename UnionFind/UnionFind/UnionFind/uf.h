#ifndef UF_H
#include<iostream>
using namespace std;
class uf
{
private:
	//采用weighted quick-union的思想，因为quick-union会导致树的深度很深，即如果输入的数据是有序的，像我在上一版本输入的数据那样，会导致树退化成一条链条
	//采用权重可以考虑两颗树的深度，权衡后，看是p接到q上还是q接到p上，之前不进行判断直接q接到p上。
	int *sz;
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
		sz = new int[N];
		for (int i = 0; i < N; i++)
		{
			id[i] = i;//开始时每个数字的组号即下标
			//刚开始的权重都为1
			sz[i] = 1;
		}
	}
	//查找这个点所在的组号
	int Find(int p)
	{
		//根节点具有id[root]=root的性质
		if (p != id[p])
		return Find(id[p]);
		return p;
		//下面这个就是路径压缩的，但是一次只能压缩一个点的路径，个人觉得效果并不如权重的效果好。
		/*while (p != id[p])
		{
			// 将p节点的父节点设置为它的爷爷节点  
			id[p] = id[id[p]];
			p = id[p];
		}
		return p;*/
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
			//合并的时候考虑两棵树的权重
			if (sz[pId] < sz[qId])
			{
				id[pId] = qId;
				sz[qId] += sz[pId];
			}
			else
			{
				id[qId] = pId;
				sz[pId] += sz[qId];
			}
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