#include "pch.h"
#include "TreeClass.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TreeClass::TreeClass()
{
}

TreeClass::~TreeClass()
{
}

void TreeClass::insert(int key) {
	if (head == nullptr) //���� ������ ������, ������ ������ �������
	{
		head = new TreeNode(key);
	}
	else
	{
		TreeNode * current = head;
		bool end = 0; //�������� �� �� ����� ������

		while (!end) { //��������� ���� �� �����, ��������� ���� ������ �������� � ������� � ������
			if (key < current->key)// ���� ��� ���� ������ ���������� ����� ������, �� ���������� �����
			{

				if (current->left != nullptr) //���� �� �������� �������, �� ���������� ����
					current = current->left;
				else // ���� ��������, ������ ����� �� ���� ������� � ����� ������ 
				{
					current->left = new TreeNode(key); 
					current->left->up = current;
					end = 1;
				}

			}
			else // ���� ��� ���� ������ ��� ����� ���������� ����� ������, �� ���������� ������
			{

				if (current->right != nullptr) //���� �� �������� �������, �� ���������� ����
					current = current->right;
				else // ���� ��������, ������ ������ �� ���� ������� � ����� ������
				{
					current->right = new TreeNode(key);
					current->right->up = current;
					end = 1;
				}


			}
		}

	}
}

TreeClass::TreeNode::TreeNode(int key)
{
	this->key = key;
}

TreeClass::TreeNode::~TreeNode()
{
}


void TreeClass::print_Tree(TreeNode * p, int level)
{
	if (p)
	{
		print_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "     ";
		cout << p->key << "<" << endl;
		print_Tree(p->left, level + 1);
	}
}



Iterator::Iterator()
{
}
Iterator::~Iterator()
{
	
}

TreeClass::Dft_iterator::Dft_iterator(TreeClass* tree)
{
	current = tree->head; // ������ � ������ ������ �������� ������ ��� ������ ��������� ������ � �������
	while ((current->left != nullptr) || (current->right != nullptr))
	{
		if (current->left == nullptr)
		{
			current = current->right;
		}
		else
			current = current->left;
	}
	// genialnii kostil dlya pervogo elementa
	TreeNode * temp = new TreeNode(0);
	temp->up = current;
	current = temp;
	// tolko hz kak udalit' etot temp potom

	
	/*
	current->right = new TreeNode(0);
	current->right->up = current;
	current = current->right;
	*/
}

TreeClass::Dft_iterator::~Dft_iterator()
{
	
}

bool TreeClass::Dft_iterator::has_next() 
{
	return (current->up != nullptr);
}
int TreeClass::Dft_iterator::next()
{
	if (has_next()) // ���� ���� ���� ����
	{
		if ((current->up->right != nullptr) && (current->up->right != current)) //���� ����� ������ �� ������ �����, �� ��������
		{
			current = current->up->right;
			while ((current->left != nullptr) || (current->right != nullptr)) // ��� � ����� ������ ������� ����� (�� ����������� �����)
			{
				if (current->left == nullptr)
				{
					current = current->right;
				}
				else
					current = current->left;
			}
		}
		else // ���� ������ ����� ���, ����������� �����
			current = current->up;
	}
	else // ���� ������ �� ������
		throw out_of_range("Tree is over");

	return current->key; //���������� ���� ��������
}


Iterator * TreeClass::create_dft_iterator()
{
	Dft_iterator * dft_iterator = new Dft_iterator(this);
	return dft_iterator;
}

