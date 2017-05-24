#include "mod2_lista5.h"

#include <iostream>


Heap::Heap()
{

}


Heap::Heap(const std::vector<int>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		push(values[i]);
	}
}


Heap::Heap(const Heap& other)
{
	for (unsigned int i = 0; i < other._container.size(); i++)
	{
		push(other._container[i]);
	}
}


Heap::~Heap()
{
}


unsigned int Heap::size()
{
	return _container.size();
}


void Heap::push(int value)
{
	int aux;
	int currIndex = _container.size();
	_container.push_back(value);

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
	if (_container.size() != 0)
		return _container[0];

	// como o retorno tem que ser inteiro na falta de um número melhor para retornar foi escolhido -1
	return -1;
}


void Heap::pop()
{
	if (_container.size() == 0)
		return;

	int aux, indexToSwap, currIndex = 0;

	_container[0] = _container[_container.size() - 1];
	_container.pop_back();

	while (2 * currIndex + 1 < _container.size())
	{
		if (2 * currIndex + 2 < _container.size())
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

	if (_container.size() > 0)
	{
		std::cout << _container[0];
	}
	
	for (unsigned int i = 1; i < _container.size(); i++)
	{
		std::cout << " " << _container[i];
	}

	std::cout << std::endl;
}
