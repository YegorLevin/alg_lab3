#pragma once
#include "TreeClass.h"
class TreeClass;

class Queue {


public:
	friend TreeClass;
	Queue();
	~Queue(); //Аналогично не уверен, нужен ли он
	/*Queue(TreeNode *node);*/
	void push_back(TreeNode *node); //
	TreeNode* pop_front(); //


private:
	class QueueNode {
	public:
		friend Queue;
		friend TreeClass;
		QueueNode(TreeNode *node);
		~QueueNode(); //Аналогично не уверен, нужен ли он
	private:
		TreeNode *tree_node;
		QueueNode *next;
	};
	QueueNode *head; 
	QueueNode *tail; 

};

