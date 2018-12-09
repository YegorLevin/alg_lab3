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


	void insert(int); // добавление элемента в дерево по ключу
	//bool contains(int); // поиск элемента в дереве по ключу
	//void remove(int); // удаление элемента дерева по ключу

	TreeNode * head;
};

