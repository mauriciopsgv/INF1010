#include "mod1_lista3.h"
#include <iostream>

Avl::Avl()
	: _root(nullptr), _cursor(nullptr)
{
}


Avl::Avl(const int key) : _cursor(nullptr)
{
	AvlNode * root = new AvlNode();
	root->_balance_factor = 0;
	root->_left = nullptr;
	root->_right = nullptr;
	root->_up = nullptr;
	root->_key = key;
	_root = root;
}


Avl::Avl(const Avl& orig)
	: _root(nullptr), _cursor(nullptr)
{
}


Avl::~Avl()
{
}


int Avl::height()
{
	return 0;
}


void Avl::insert(int key)
{
}


void Avl::show(const std::string& title)
{
	std::cout << title << std::endl;
	show_rec(_root);
	std::cout << std::endl;
}


bool Avl::first()
{
	AvlNode * minNode = _root;
	if (minNode == nullptr)
	{
		return false;
	}
	while (minNode->_left != nullptr)
	{
		minNode = minNode->_left;
	}
	_cursor = minNode;
	return true;
}


bool Avl::last()
{
	AvlNode * minNode = _root;
	if (minNode == nullptr)
	{
		return false;
	}
	while (minNode->_right != nullptr)
	{
		minNode = minNode->_right;
	}
	_cursor = minNode;
	return true;
}


bool Avl::next()
{
	AvlNode * previousCursorValue = _cursor;
	if (_cursor == nullptr)
	{
		return false;
	}
	if (_cursor->_right != nullptr)
	{
		AvlNode * minNode = _cursor->_right;
		while (minNode->_left != nullptr)
		{
			minNode = minNode->_left;
		}
		_cursor = minNode;
		return true;
	}
	if (_cursor->_up != nullptr)
	{
		AvlNode * fatherNode = _cursor->_up;
		while (fatherNode->_up != nullptr)
		{
			if (fatherNode->_key > _cursor->_key)
			{
				_cursor = fatherNode;
				return true;
			}
			fatherNode = fatherNode->_up;
		}
		if (fatherNode->_key > _cursor->_key)
		{
			_cursor = fatherNode;
			return true;
		}
	}
	_cursor = previousCursorValue;
	return false;
}


bool Avl::prev()
{
	AvlNode * previousCursorValue = _cursor;
	if (_cursor == nullptr)
	{
		return false;
	}
	if (_cursor->_left != nullptr)
	{
		AvlNode * maxNode = _cursor->_left;
		while (maxNode->_right != nullptr)
		{
			maxNode = maxNode->_right;
		}
		_cursor = maxNode;
		return true;
	}
	if (_cursor->_up != nullptr)
	{
		AvlNode * fatherNode = _cursor->_up;
		while (fatherNode->_up != nullptr)
		{
			if (fatherNode->_key < _cursor->_key)
			{
				_cursor = fatherNode;
				return true;
			}
			fatherNode = fatherNode->_up;
		}
		if (fatherNode->_key < _cursor->_key)
		{
			_cursor = fatherNode;
			return true;
		}
	}
	_cursor = previousCursorValue;
	return false;
}


int Avl::value()
{
	if (_cursor == nullptr)
	{
		return 0;
	}
	return _cursor->_key;
}


void Avl::show_rec(AvlNode* node)
{
	if (node != nullptr)
	{
		std::cout << "<";
		std::cout << node->_key;
		show_rec(node->_left);
		show_rec(node->_right);
		std::cout << ">";
	}
	else 
	{
		std::cout << ".";
	}
}

