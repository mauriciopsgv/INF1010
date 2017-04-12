#include <iostream>
#include "mod1_lista2.h"

using namespace std;

Abb::Abb() : _root(nullptr), _cursor(nullptr)
{
}


Abb::Abb(int key)
{
	Node * firstNode = new Node();
	firstNode->_key = key;
	firstNode->_up = nullptr;
	firstNode->_left = nullptr;
	firstNode->_right = nullptr;
	_root = firstNode;
	_cursor = firstNode;
}

Node * copyAbb(Node * &newTree, Node * oldTree)
{
	if (oldTree == nullptr)
		return nullptr;
	newTree = new Node();
	newTree->_key = oldTree->_key;
	newTree->_up = nullptr;
	
	newTree->_left = copyAbb(newTree->_left, oldTree->_left);
	newTree->_right = copyAbb(newTree->_right, oldTree->_right);

	if (newTree->_left != nullptr)
		newTree->_left->_up = newTree;
	if (newTree->_right != nullptr)
		newTree->_right->_up = newTree;
	return newTree;
}

Abb::Abb(const Abb& orig)
{
	if (orig._root == nullptr)
	{
		_root = nullptr;
	}
	else
	{
		copyAbb(_root, orig._root);
	}
	_cursor = nullptr;
}

Abb::~Abb()
{
	deleterec(_root);
	delete _root;
}


void Abb::insert(int key)
{
	_root = insertrec(_root, key);
}

bool Abb::remove(int key)
{
	Node * nodeToBeRemoved = search(key);
	if (nodeToBeRemoved == nullptr)
	{
		return false;
	}
	_cursor = nodeToBeRemoved;

	if (next() && (_cursor->_left == nullptr || _cursor->_right == nullptr) )
	{
		int nextKey = _cursor->_key;
		removesimplenode(_cursor);
		nodeToBeRemoved->_key = nextKey;
	}
	else
	{
		removesimplenode(nodeToBeRemoved);
	}
	return true;
}

void Abb::show(const std::string& title)
{
	cout << title << endl;
	showrec(_root);
	cout << endl;
}


void Abb::order(const std::string& title)
{
	cout << title << endl;
	orderrec(_root);
	cout << endl;
}

int Abb::min()
{
	Node * minNode = _root;
	if (minNode == nullptr)
	{
		return 0;
	}
	while (minNode->_left != nullptr)
	{
		minNode = minNode->_left;
	}
	return minNode->_key;
}


bool Abb::first()
{
	Node * minNode = _root;
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


bool Abb::last()
{
	Node * minNode = _root;
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


bool Abb::next()
{
	Node * previousCursorValue = _cursor;
	if (_cursor == nullptr)
	{
		return false;
	}
	if (_cursor->_right != nullptr)
	{
		Node * minNode = _cursor->_right;
		while (minNode->_left != nullptr)
		{
			minNode = minNode->_left;
		}
		_cursor = minNode;
		return true;
	}
	if (_cursor->_up != nullptr)
	{
		Node * fatherNode = _cursor->_up;
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


bool Abb::prev()
{
	Node * previousCursorValue = _cursor;
	if (_cursor == nullptr)
	{
		return false;
	}
	if (_cursor->_left != nullptr)
	{
		Node * maxNode = _cursor->_left;
		while (maxNode->_right != nullptr)
		{
			maxNode = maxNode->_right;
		}
		_cursor = maxNode;
		return true;
	}
	if (_cursor->_up != nullptr)
	{
		Node * fatherNode = _cursor->_up;
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


int Abb::value()
{
	if (_cursor == nullptr)
	{
		return 0;
	}
	return _cursor->_key;
}


Node* Abb::search(int key)
{
	return searchrec(_root, key);
}


Node* Abb::searchrec(Node* node, int key)
{
	if (node == nullptr)
		return nullptr;
	if (node->_key == key)
		return node;
	if (node->_key > key)
		return searchrec(node->_left, key);
	return searchrec(node->_right, key);
}


void Abb::deleterec(Node* root)
{
	if (root == nullptr) return;
	deleterec(root->_left);
	deleterec(root->_right);
	delete root->_left;
	delete root->_right;
}


Node* Abb::insertrec(Node* a, int key)
{
	if (a == nullptr){
		Node * p = new Node();
		p->_key = key;
		p->_left = nullptr;
		p->_right = nullptr;
		return p;
	}

	if (key > a->_key)
	{
		a->_right = insertrec(a->_right, key);
		a->_right->_up = a;
	} 
	else if (key < a->_key)
	{
		a->_left = insertrec(a->_left, key);
		a->_left->_up = a;
	}
	return a;
}


void Abb::showrec(Node* a)
{
	if (a == nullptr) {
		cout << ".";
		return;
	}

	cout << "<" << a->_key;
	showrec(a->_left);
	showrec(a->_right);
	cout << ">";
}


void Abb::orderrec(Node* a)
{
	if (a == nullptr)
		return;

	orderrec(a->_left);
	cout << a->_key << ",";
	orderrec(a->_right);
}


void Abb::removesimplenode(Node* node)
{
	Node * subArvore = node->_left;
	if (subArvore == nullptr) subArvore = node->_right;
	if (subArvore != nullptr) subArvore->_up = node->_up;

	if (node->_up == nullptr)
	{
		_root = subArvore;
		if (subArvore != nullptr)
			subArvore->_up = nullptr;
	}
	else
	{
		if (node->_up->_key > node->_key)
			node->_up->_left = subArvore;
		else
			node->_up->_right = subArvore;
		if (subArvore != nullptr)
			subArvore->_up = node->_up;
	}

	delete node;
}
