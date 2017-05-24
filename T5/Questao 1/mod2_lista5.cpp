#include "mod2_lista5.h"

#include <iostream>


Heap::Heap()
	: _size(0)
{

}


Heap::Heap(int* values, unsigned int size) : _size(0)
{
	for (int i = 0; i < size; i++)
	{
		push(values[i]);
	}
}


Heap::Heap(const Heap& other) : _size(0)
{
	for (unsigned int i = 0; i < other._size; i++)
	{
		push(other._container[i]);
	}
}


Heap::~Heap()
{
}


unsigned int Heap::size()
{
	return _size;
}


void Heap::push(int value)
{
	if (_size == MAX_ELEMENTS)
		return;

	int aux;
	int currIndex = _size;
	_container[_size] = value;
	_size++;

	while (currIndex != 0 && value < _container[(currIndex-1)/2] )
	{
		aux = _container[(currIndex - 1) / 2];
		_container[(currIndex - 1) / 2] = _container[currIndex];
		_container[currIndex] = aux;
		currIndex = (currIndex - 1) / 2;
	}
}


int Heap::top()
{
	if (_size != 0)
		return _container[0];
	return -1;
}


void Heap::pop()
{
	if (_size == 0)
		return;

	int aux, indexToSwap, currIndex = 0;

	_container[0] = _container[_size - 1];
	_size--;

	while (2 * currIndex + 1 < _size)
	{
		if (2 * currIndex + 2 < _size)
		{
			if (_container[2 * currIndex + 1] < _container[2 * currIndex + 2])
			{
				indexToSwap = 2 * currIndex + 1;
			}
			else
			{
				indexToSwap = 2 * currIndex + 2;
			}
		}
		else
		{
			indexToSwap = 2 * currIndex + 1;
		}

		if (_container[currIndex] > _container[indexToSwap])
		{
			aux = _container[currIndex];
			_container[currIndex] = _container[indexToSwap];
			_container[indexToSwap] = aux;
			currIndex = indexToSwap;
		}
		else
		{
			break;
		}
	}
}


void Heap::show(const std::string& title)
{
	std::cout << title << " ";

	if (_size > 0)
	{
		std::cout << _container[0];
	}
	
	for (unsigned int i = 1; i < _size; i++)
	{
		std::cout << " " << _container[i];
	}

	std::cout << std::endl;
}
