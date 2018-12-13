#pragma once
#include "TreeClass.h"
class TreeClass;
class Queue;

class TreeNode
{
	
public:
	friend Queue;
	friend void tree_sort_rec(TreeNode* head, Queue* tree_node_queue);
	friend TreeClass;
	int get_key();
	TreeNode(int);
	~TreeNode();

private:
	int key;
	TreeNode * left;
	TreeNode * right;
	TreeNode * up;
};