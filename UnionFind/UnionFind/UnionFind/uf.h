#ifndef UF_H
#include<iostream>
using namespace std;
class uf
{
private:
	//����weighted quick-union��˼�룬��Ϊquick-union�ᵼ��������Ⱥ����������������������ģ���������һ�汾����������������ᵼ�����˻���һ������
	//����Ȩ�ؿ��Կ�������������ȣ�Ȩ��󣬿���p�ӵ�q�ϻ���q�ӵ�p�ϣ�֮ǰ�������ж�ֱ��q�ӵ�p�ϡ�
	int *sz;
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
		sz = new int[N];
		for (int i = 0; i < N; i++)
		{
			id[i] = i;//��ʼʱÿ�����ֵ���ż��±�
			//�տ�ʼ��Ȩ�ض�Ϊ1
			sz[i] = 1;
		}
	}
	//������������ڵ����
	int Find(int p)
	{
		//���ڵ����id[root]=root������
		if (p != id[p])
		return Find(id[p]);
		return p;
		//�����������·��ѹ���ģ�����һ��ֻ��ѹ��һ�����·�������˾���Ч��������Ȩ�ص�Ч���á�
		/*while (p != id[p])
		{
			// ��p�ڵ�ĸ��ڵ�����Ϊ����үү�ڵ�  
			id[p] = id[id[p]];
			p = id[p];
		}
		return p;*/
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
			//�ϲ���ʱ������������Ȩ��
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