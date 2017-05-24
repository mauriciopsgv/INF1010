#ifndef MOD2_LISTA5_H
#define MOD2_LISTA5_H

#include <string>
#include <vector>

template <typename T>
class Heap /* Min-Heap */
{
public:
	//Construtor vazio
	Heap();

	//Constroi o heap a partir de um vetor de elementos
	Heap(const std::vector<T>& values);

	//Constroi o heap a partir de outro heap
	Heap(const Heap& other);

	//Destroi o heap
	~Heap();

	//Retorna o numero de elementos atualmente no heap
	unsigned int size();
	
	//Insere um novo elemento
	void push(T value);

	//Retorna o elemento do topo
	T top();

	//Remove o elemento do topo
	void pop();

	//Exibe os elementos do heap
	void show(const std::string& title);

private:

	/* Funcoes privadas que julgar necessarias */

private:
	//Contem os elementos do heap
	std::vector<T> _container;
};

#endif

template <typename T>
Heap<T>::Heap()
{

}

template <typename T>
Heap<T>::Heap(const std::vector<T>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		push(values[i]);
	}
}

template <typename T>
Heap<T>::Heap(const Heap& other)
{
	for (unsigned int i = 0; i < other._container.size(); i++)
	{
		push(other._container[i]);
	}
}

template <typename T>
Heap<T>::~Heap()
{
}

template <typename T>
unsigned int Heap<T>::size()
{
	return _container.size();
}

template <typename T>
void Heap<T>::push(T value)
{
	T aux;
	int currIndex = _container.size();
	_container.push_back(value);

	while (currIndex != 0 && value < _container[(currIndex - 1) / 2])
	{
		aux = _container[(currIndex - 1) / 2];
		_container[(currIndex - 1) / 2] = _container[currIndex];
		_container[currIndex] = aux;
		currIndex = (currIndex - 1) / 2;
	}
}

template <typename T>
T Heap<T>::top()
{
	return _container[0];
}

template <typename T>
void Heap<T>::pop()
{
	if (_container.size() == 0)
		return;

	T aux;
	int indexToSwap, currIndex = 0;

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

template <typename T>
void Heap<T>::show(const std::string& title)
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

