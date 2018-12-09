#pragma once

class Iterator
{
public:
	Iterator();
	~Iterator();
	virtual int next() = 0;
	virtual bool has_next() = 0;

private:
	TreeNode * current;
};

class Dft_iterator : public Iterator
{
public:
	Dft_iterator(TreeClass* tree);
	~Dft_iterator();
	int next() override;
	bool has_next() override;

private:
	TreeNode * current;
};


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

private:
	
public:
	TreeClass();
	~TreeClass();
	void print_Tree(TreeNode * p, int level);


	void insert(int); // ���������� �������� � ������ �� �����
	//bool contains(int); // ����� �������� � ������ �� �����
	//void remove(int); // �������� �������� ������ �� �����
	Iterator * create_dft_iterator(); // �������� ���������, ������������ ������ ������ � ������� (depth-first traverse)


	TreeNode * head;

	
};


