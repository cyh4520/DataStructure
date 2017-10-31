#ifndef AVLTREE_H
#include "stdafx.h"
#include<iostream>
using namespace std;
#define Max(a,b) (((a)>(b))?(a):(b))
struct treeNode
{
	int value;
	int height;//高度 不是深度
	treeNode *left;
	treeNode *right;
};
typedef treeNode *node;
class AvlTree
{
public:
node init(node T);
node insert(node T,int num);
int Height(node T);
node SingleRotateLeft(node T);
node SingleRotateRight(node T);
node DoubleRotateLeft(node T);
node DoubleRotateRight(node T);
void show(node T);
};
#endif