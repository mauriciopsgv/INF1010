#include "mod1_lista3.h"
#include <iostream>
#include <stdlib.h>

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
	delete_rec(_root);
	delete _root;
}


int Avl::height()
{
	return height_rec(_root);
}


void Avl::insert(int key)
{
	_root = insert_rec(_root, key);
	balanceItself();
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

AvlNode* Avl::insert_rec(AvlNode* a, int key)
{
	if (a == nullptr) {
		AvlNode *p = new AvlNode();
		p->_key = key;
		p->_left = nullptr;
		p->_right = nullptr;
		return p;
	}

	if (key > a->_key)
	{
		a->_right = insert_rec(a->_right, key);
		a->_right->_up = a;
	}
	else if (key < a->_key)
	{
		a->_left = insert_rec(a->_left, key);
		a->_left->_up = a;
	}
	return a;
}

void Avl::recalculateBalanceFactor(AvlNode * node)
{
	if (node == nullptr)
		return;

	node->_balance_factor = height_rec(node->_right) - height_rec(node->_left);
	recalculateBalanceFactor(node->_left);
	recalculateBalanceFactor(node->_right);
}

void Avl::balanceItself()
{
	bool isBalanced = false;

	while (!isBalanced)
	{
		recalculateBalanceFactor(_root);
		isBalanced = checkBalance_rec(_root);
	}
	recalculateBalanceFactor(_root);
}

bool Avl::checkBalance_rec(AvlNode* node)
{
	if (node == nullptr)
		return true;

	if (abs(node->_balance_factor) > 1)
	{
		balanceThis(node);
		return false;
	}

	return checkBalance_rec(node->_left) && checkBalance_rec(node->_right);
		
}

void Avl::balanceThis(AvlNode * node)
{
	if (node->_balance_factor > 0)
	{
		if (node->_right->_balance_factor > 0)
			leftRotation(node, node->_right);
		else
		{
			rightRotation(node->_right, node->_right->_left);
			leftRotation(node, node->_right);
		}
	}
	else
	{
		if (node->_left->_balance_factor < 0)
			rightRotation(node, node->_left);
		else
		{
			leftRotation(node->_left, node->_left->_right);
			rightRotation(node, node->_left);
		}
	}
}

void Avl::leftRotation(AvlNode * nodeR, AvlNode * nodeT)
{
	if (nodeR->_up == nullptr)
	{
		_root = nodeT;
		nodeT->_up = nullptr;
	}
	else
		setParent(nodeT, nodeR->_up);

	nodeR->_right = nodeT->_left;
	nodeT->_left = nodeR;
	nodeR->_up = nodeT;
}


void Avl::rightRotation(AvlNode * nodeR, AvlNode * nodeT)
{
	if (nodeR->_up == nullptr)
	{
		_root = nodeT;
		nodeT->_up = nullptr;
	}
	else
		setParent(nodeT, nodeR->_up);

	nodeR->_left = nodeT->_right;
	nodeT->_right = nodeR;
	nodeR->_up = nodeT;
	nodeT->_up = nodeR->_up;
}

void Avl::setParent(AvlNode * node, AvlNode * nodeParent)
{
	node->_up = nodeParent;
	if (node->_key < nodeParent->_key)
		nodeParent->_left = node;
	else
		nodeParent->_right = node;
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

int Avl::height_rec(AvlNode * node)
{
	if (node == nullptr)
		return -1;
	
	int rightHeight = height_rec(node->_right);
	int leftHeight = height_rec(node->_left);

	if (leftHeight > rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}

void Avl::delete_rec(AvlNode * root)
{
	if (root == nullptr) return;
	delete_rec(root->_left);
	delete_rec(root->_right);
	delete root->_left;
	delete root->_right;
}

