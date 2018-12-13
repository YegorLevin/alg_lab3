#pragma once
#include "TreeClass.h"
class TreeClass;

class TreeNode
{
	
public:
	friend TreeClass;
	TreeNode(int);
	~TreeNode();

private:
	int key;
	TreeNode * left;
	TreeNode * right;
	TreeNode * up;
};