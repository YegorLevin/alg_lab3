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
	Iterator * iterator = create_dft_iterator();
	while (iterator->has_next())
	{
		remove(iterator->next());
	}
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

TreeNode::TreeNode(int key)
{
	this->key = key;
}

TreeNode::~TreeNode()
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

bool TreeClass::contains(int key)
{
	Iterator * iterator = create_dft_iterator(); // �������� ��������� � ������� (��������)
	bool contains = 0; // �������� �� ������ ���� �������
	while (!contains && iterator->has_next()) // ���� �� ����� ��� �� ����������� ������
	{
		if (iterator->next() == key) // ���������� �������� � ���������� � ��������� ������
		{
			contains = 1; // ���� ����� ������ ����
		}
	}
	return contains;
	delete iterator;
}

void TreeClass::remove(int key)
{
	if (contains(key)) // ���� ����� ������� ���� � ������
	{
		bool found = 0; 
		Iterator * iterator = create_dft_iterator();
		while (!found && iterator->has_next()) // ���� �� ����� ��� �� ����������� ������
		{
			if (iterator->next() == key) // ���������� �������� � ���������� � ��������� ������
			{
				found = 1; // ���� ����� ������ ����
			}
		}

		TreeNode* deleting_node = iterator->current;
		if ((deleting_node->left != nullptr) && (deleting_node->right != nullptr)) // ���� � ���������� ���� ��� ��������
		{
			TreeNode* left_stick = deleting_node->left;
			TreeNode* right_stick = deleting_node->right;
			//������������� ������ �������� 
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				right_stick->up = deleting_node->up; //��������� ���� ������ �������� ����� ����� � ������� ��������� ���������� ��������
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
				{
					deleting_node->up->right = right_stick; //������ ���������� ������ ����				
				}
				else // ���� ��� ����� ������� �������� ��������
					deleting_node->up->left = right_stick; //������ ���������� ������ ����
			}
			else // ���� ��������� ������� - ������
			{
				right_stick->up = nullptr;
				head = right_stick; // �������� ������ �������� ���������� �������
				

			}

				while (right_stick->left != nullptr) // ������� ����� ����� ������� ������ ��������
				{
					right_stick = right_stick->left;
				}
				right_stick->left = left_stick; //������������ ����� �������� � ����� ����� ������ ��������
				left_stick->up = right_stick;
			

			
		}
		else if (deleting_node->left != nullptr) // ���� ���� ������ ����� ��������
		{
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				TreeNode* left_stick = deleting_node->left;
				left_stick->up = deleting_node->up; //����������� ����� ����� ����� ����� � �������� �������� ���������� 
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
					deleting_node->up->right = left_stick; //����������� ����� ����� ������ ���� � �������� �������� ����������
				else
					deleting_node->up->left = left_stick; //����������� ����� ����� ������ ���� � �������� �������� ����������
			}
			else // ���� ��������� ������� - ������
			{ 
				head = deleting_node->left; //������ ������� �������� ���� ��������
				deleting_node->left->up = nullptr;
			}

		}
		else if (deleting_node->right != nullptr) // ���� ���� ������ ������ ��������
		{
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				TreeNode* right_stick = deleting_node->right;
				right_stick->up = deleting_node->up; //����������� ������ ����� ����� ����� � �������� �������� ���������� 
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
					deleting_node->up->right = right_stick; //����������� ������ ����� ������ ���� � �������� �������� ����������
				else
					deleting_node->up->left = right_stick; //����������� ������ ����� ������ ���� � �������� �������� ����������
			}
			else // ���� ��������� ������� - ������
			{
				head = deleting_node->right;  //������ ������� �������� ���� ��������
				deleting_node->right->up = nullptr;
			}
				
			
		}
		else // ���� ��� ��������
		{
			if (deleting_node != head) // ���� ��������� ������� �� ������
			{
				if (deleting_node->key >= deleting_node->up->key) // ��������� ������� �������� ������ ��� �����
					deleting_node->up->right = nullptr; //������� � ���� ����
				else
					deleting_node->up->left = nullptr;
			}
			else // ���� ��������� ������� - ������
				head = nullptr; //�������� ��������� �� ������
		}
					
		delete deleting_node;
		delete iterator;

	}
	else
		throw out_of_range("No equal key");
	
}