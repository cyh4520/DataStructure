// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<queue>
#include<map>
using namespace std;

map<string, float> cmap ;

typedef struct treeNode
{
	string value;
	treeNode *left;
	treeNode *right;
}treenode;
treenode *root;
void init()
{
	cmap["a"] = 0.22;
	cmap["am"] = 0.18;
	cmap["and"] = 0.20;
	cmap["egg"] = 0.05;
	cmap["if"] = 0.25;
	cmap["the"] = 0.02;
	cmap["two"] = 0.08;
}
string findmax()
{
	map<string, float>::iterator it;
	it = cmap.begin();

	string now="";
	float max = 0.0;;
	while (it != cmap.end())
	{
		//���ָ���Ϊ1.0������Ϊ�Ѿ����ʹ�
		if (it->second > max&&it->second!=1.0)
		{
			max = it->second;
			now = it->first;
		}
		it++;
	}
	return now;
}
treenode* newNode(string str)
{
	treenode *node = new treenode();
	node->value = str;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//����֮ǰд�ģ�д�����ʱ��о��������õݹ�ʵ�֣������Ļ��ᵼ��һֱ������һ�����ӣ�������һ�߲�����
//���������������õݹ�ʵ�֣���Ҫ�ⲻ�������Ŷ�����������һ�ö�������������Բ�����ƽ�������Ľ�㲻���������ȥ�ģ�����ߵĿ϶��ȸ�С���ұߵĿ϶��ȸ��󣬲���һֱ����
treenode* insert(string str,treenode* node)
{
	if (node == NULL)
	{
		node = newNode(str);
	}
	else
	{
		int cp = node->value.compare(str);
		//node>str
		if (cp > 0)
		{
			node->left = insert(str, node->left);
		}
		if (cp < 0)
		{
			node->right = insert(str, node->right);
		}
	}
	return node;
}

void findRoot()
{
	string rt = findmax();
	cmap.at(rt) = 1.0;
	root = NULL;
	root=insert(rt, root);
	for (int i = 0; i < cmap.size() - 1;i++)
	{
		string now = findmax();
		root=insert(now, root);
		cmap.at(now) = 1.0;
	}
}
//�������
void print(treenode *now)
{
	queue<treenode*> q;
	q.push(now);
	while (!q.empty())
	{
		treenode *nd = q.front();
		q.pop();
		printf("%s ", nd->value.c_str());
		if (nd->left) q.push(nd->left);
		if (nd->right) q.push(nd->right);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	findRoot();
	print(root);
	system("pause");
	return 0;
}

