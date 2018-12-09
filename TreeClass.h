#pragma once


class TreeClass
{

private:
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

public:
	TreeClass();
	~TreeClass();
	void print_Tree(TreeNode * p, int level);


	void insert(int); // ���������� �������� � ������ �� �����
	//bool contains(int); // ����� �������� � ������ �� �����
	//void remove(int); // �������� �������� ������ �� �����

	TreeNode * head;
};

