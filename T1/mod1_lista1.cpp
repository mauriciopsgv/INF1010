#include "mod1_lista1.h"
#include <iostream>

List::List()
	: first(nullptr)
	, last(nullptr)
{
}


List::List(const List& list)
{
	Node * currentOriginal = list.first;
	if (list.first == nullptr)
	{
		first = nullptr;
		last = nullptr;
		return;
	}

	while (currentOriginal != list.last)
	{
		push_back(currentOriginal->val);
		currentOriginal = currentOriginal->next;
	}
	if (currentOriginal != nullptr)
	{
		push_back(currentOriginal->val);
	}
}


List::~List()
{
	Node * temp;
	Node * current = first;
	while (current != last)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
	if (current != nullptr)
	{
		delete current;
	}	
}


void List::push_back(const int& element)
{
	Node* newNode = new Node();
	newNode->val = element;
	newNode->next = nullptr;

	if (first == nullptr)
	{
		newNode->prev = nullptr;
		first = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
}


void List::push_front(const int& element)
{
	Node* newNode = new Node();
	newNode->val = element;
	newNode->prev = nullptr;

	if (first == nullptr)
	{
		newNode->next = nullptr;
		first = newNode;
		last = newNode;
	}
	else
	{
		first->prev = newNode;
		newNode->next = first;
		first = newNode;
	}
}


void List::pop_back()
{
	if (first == nullptr)
	{
		std::cout << "Voce tentou remover um no de uma lista vazia" << std::endl;
		return;
	}

	Node * temp = last;
	last = last->prev;
	delete temp;

	if (last == nullptr)
	{
		first = nullptr;
	}
	else
	{
		last->next = nullptr;
	}
}


void List::pop_front()
{
	if (first == nullptr)
	{
		std::cout << "Voce tentou remover um no de uma lista vazia" << std::endl;
		return;
	}

	Node * temp = first;
	first = first->next;
	delete temp;

	if (first == nullptr)
	{
		last = nullptr;
	}
	else
	{
		first->prev = nullptr;
	}
}


unsigned int List::size()
{
	if (first == nullptr)
		return 0;

	unsigned int count = 0;
	Node * current = first;
	while (current != last)
	{
		count++;
		current = current->next;
	}
	return ++count;

}


void List::remove(const int& element)
{
	if (first == nullptr)
	{
		std::cout << "Nao foi possivel encontrar o elemento pois a lista esta vazia" << std::endl;
		return;
	}
	Node * current = first->next;

	if (first->val == element)
	{
		pop_front();
		return;
	}

	if (current == nullptr)
	{
		std::cout << "A lista nao possui nenhuma ocorrencia desse elemento" << std::endl;
		return;
	}

	while (current != last)
	{
		if (current->val == element)
		{
			Node * temp = current->prev;
			temp->next = current->next;
			current->next->prev = temp;
			delete current;
			return;
		}
		current = current->next;
	}
	if (current != nullptr && current->val == element)
	{
		pop_back();
		return;
	}
	std::cout << "A lista nao possui nenhuma ocorrencia desse elemento" << std::endl;
}


void List::print()
{
	Node * current = first;
	while (current != last)
	{
		std::cout << current->val << " ";
		current = current->next;
	}
	if (current != nullptr)
	{
		std::cout << current->val << std::endl;
	}
}

void List::sort()
{
	if (first == nullptr)
	{
		std::cout << "Nao eh possivel ordenar a lista ja que a mesma esta vazia" << std::endl;
		return;
	}

	int aux;
	Node * min = first;
	Node * tempFirst = first;
	Node * current = first->next;

	while (tempFirst != last)
	{
		while (current != nullptr)
		{
			if (current->val < min->val)
			{
				min = current;
			}
			current = current->next;
		}
		aux = tempFirst->val;
		tempFirst->val = min->val;
		min->val = aux;
		tempFirst = tempFirst->next;
		current = tempFirst;
		min = tempFirst;
	}
}