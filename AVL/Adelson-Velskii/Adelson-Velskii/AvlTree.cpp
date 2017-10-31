#include "stdafx.h"
#include"AvlTree.h"
#include<stdlib.h>
node AvlTree::init(node T)
{
	if (T != NULL)
	{
		init(T->left);
		init(T->right);
	}
	return NULL;
}
int AvlTree::Height(node T)
{
	if (T == NULL)
		return -1;
	return T->height;
}
node AvlTree::insert(node T, int num)
{
	if (T == NULL)
	{
		T = new struct treeNode();
		T->left = NULL;
		T->right = NULL;
		T->value = num;
	}
	else
	{
		if (num < T->value)
		{
			T->left = insert(T->left, num);
			//插入后判断高度是否需要旋转
			if (Height(T->left) - Height(T->right) == 2)
			{
				if (num<T->left->value)
					T = SingleRotateLeft(T);
				else
					T = DoubleRotateLeft(T);
			}
		}
		if (num>T->value)
		{
			T->right = insert(T->right, num);
			if (Height(T->right) - Height(T->left) == 2)
			{
				if (T->right&&num > T->right->value)
					T = SingleRotateRight(T);
				else
					T = DoubleRotateRight(T);
			}
		}
	}
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return T;
}
//图参照书上82页
node AvlTree::SingleRotateLeft(node T)
{
	node temp;
	temp = T->left;
	T->left=temp->right;
	temp->right = T;
	temp->height = Max(Height(temp->left), T->height) + 1;
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return temp;
}

node AvlTree::SingleRotateRight(node T)
{
	node temp;
	temp = T->right;
	T->right = temp->left;
	temp->left = T;
	temp->height = Max(Height(temp->right), T->height) + 1;
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return temp;
}
node AvlTree::DoubleRotateLeft(node T)
{
	T->left = SingleRotateRight(T->left);
	return SingleRotateLeft(T);
}
node AvlTree::DoubleRotateRight(node T)
{
	T->right = SingleRotateLeft(T->right);
	return SingleRotateRight(T);
}
void AvlTree::show(node T)
{
	if (T == NULL)
		return;
	cout << T->value << " ";
	if (T->left)
		show(T->left);
	if (T->right)
		show(T->right);
}
