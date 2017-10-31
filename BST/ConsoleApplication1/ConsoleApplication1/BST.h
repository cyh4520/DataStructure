
#ifndef BST_H
#define BST_H
	struct treeNode
	{
		int value;
		treeNode* left;
		treeNode* right;
	};
	typedef struct treeNode *node;
class BST
{

private:
	node root;
public:
	node init(node T);
	node insert(node T, int num);
	node search(node T, int num);
	node Delete(node T, int num);
	void show(node T);
	node findMin(node T);

};

#endif