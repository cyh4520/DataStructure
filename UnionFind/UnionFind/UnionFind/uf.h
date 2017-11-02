#ifndef UF_H
#include<iostream>
using namespace std;
class uf
{
private:
	//��ĸ���
	int count;
	//��������ʽ�洢����
	int *id;
	//����ĳ���
	int length;
public:
	uf(int N)
	{
		count = N;
		length = N;
		id = new int[N];
		for (int i = 0; i < N; i++)
			id[i] = i;//��ʼʱÿ�����ֵ���ż��±�
	}
	//������������ڵ����
	int Find(int p)
	{
		//���ڵ����id[root]=root������
		if (p != id[p])
		return Find(id[p]);
		return p;
	}
	//��ͨ��������
	void Union(int p, int q)
	{
		//���û����ͨ
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
	//��ѯ���������Ƿ�����ͨ
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