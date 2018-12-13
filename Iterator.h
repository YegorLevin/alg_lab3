#pragma once
#include "TreeClass.h"
class TreeClass;


class Iterator // родительский класс итератора 
{
public:
	friend TreeClass;
	Iterator();
	~Iterator();
	virtual int next() = 0;
	virtual bool has_next() = 0;
	
protected:
	TreeNode * current;
};