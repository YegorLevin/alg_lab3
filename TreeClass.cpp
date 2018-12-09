#include "pch.h"
#include "TreeClass.h"
#include <iostream>

using namespace std;

TreeClass::TreeClass()
{
}

TreeClass::~TreeClass()
{
}

void TreeClass::insert(int key) {
	if (head == nullptr)
	{
		head = new TreeNode (key);
	}
	else
	{
		TreeNode * current = head;

		while (current != nullptr) {
			if (key < current->key)
			{

				if(current->left !=nullptr)
				current = current->left;
				else
				{
					current->left = new TreeNode(key);
					current->left->up = current;
					break;
				}
				
			}
			else
			{ 

				if (current->right != nullptr)
					current = current->right;
				else
				{
					current->right = new TreeNode(key);
					current->right->up = current;
					break;
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

Dft_iterator::Dft_iterator(TreeClass* tree)
{
	current = tree->head;
	while ((current->left != nullptr) && (current->right != nullptr))
	{
		if (current->left == nullptr)
		{
			current = current->right;
		}
		else
			current = current->left;
	}
}

Dft_iterator::~Dft_iterator()
{

}

bool Dft_iterator::has_next()
{
	
}
int Dft_iterator::next()
{
	if ((current->up->right != nullptr) && (current->up->right != current))
	{
		current = current->up->right;
		while ((current->left != nullptr) && (current->right != nullptr))
		{
			if (current->left == nullptr)
			{
				current = current->right;
			}
			else
				current = current->left;
		}
	}
	else
		current = current->up;
}