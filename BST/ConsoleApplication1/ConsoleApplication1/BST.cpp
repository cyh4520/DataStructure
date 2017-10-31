#include"stdafx.h"
#include"BST.h"

node BST::init(node T)
{
	if ( T!= NULL)
	{
		init(T->left);
		init(T->right);
	}
	return NULL;
}

node BST::search(node T, int num)
{
	if (T == NULL)
		return NULL;
	if (num < T->value)
	{
		return search(T->left, num);
	}
	else if (num>T->value)
	{
		return search(T->right, num);
	}
	else 
		return T;
}

node BST::insert(node T, int num)
{
	if (T == NULL)
	{
		T = new struct treeNode();
		T->value = num;
		init(T);
	}
	else
	{
		if (num < T->value)
		{
			T->left = insert(T->left, num);
		}
		else
		{
			T->right = insert(T->right, num);
		}
	}
	return T;
}
node BST::findMin(node T)
{
	if (T == NULL)
		return NULL;
	if (T->left != NULL)
		T = findMin(T->left);
	return T;
}
node BST::Delete(node T, int num)
{
	if (T == NULL)
	{
		return NULL;
	}
	if (num > T->value)
	{
		T->right = Delete(T->right, num);
	}
	else if (num < T->value)
	{
		T->left = Delete(T->left, num);
	}
	//has two chilren
	else if (T->left&&T->right)
	{
		node temp=new struct treeNode();
		temp = findMin(T->right);
		T->value = temp->value;
		T->right = Delete(T->right, temp->value);
		delete(temp);
	}
	//has one or zero child
	else
	{
		//has one child
		if (T->left != NULL)
			T = T->left;
		else if (T->right != NULL)
			T = T->right;
		//has no child
		else
			T = NULL;
	}
	return T;

}
void BST::show(node T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->value);
	if (T->left)
		show(T->left);
	if (T->right)
		show(T->right);

}