#pragma once
class TreeNode
{
public:
	TreeNode(int);
	~TreeNode();

	int key;
	TreeNode * left;
	TreeNode * right;
	TreeNode * up;
private:

};


class TreeClass
{
public:
	TreeClass();
	~TreeClass();
	void print_Tree(TreeNode * p, int level);
	

	void insert(int); // ���������� �������� � ������ �� �����
	TreeNode * head;
private:
	
};

