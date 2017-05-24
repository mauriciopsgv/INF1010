#ifndef MOD2_LISTA5_H
#define MOD2_LISTA5_H

#include <string>
#include <vector>

class Heap /* Min-Heap */
{
public:
	//Construtor vazio
	Heap();

	//Constroi o heap a partir de um vetor de elementos
	Heap(const std::vector<int>& values);

	//Constroi o heap a partir de outro heap
	Heap(const Heap& other);

	//Destroi o heap
	~Heap();

	//Retorna o numero de elementos atualmente no heap
	unsigned int size();
	
	//Insere um novo elemento
	void push(int value);

	//Retorna o elemento do topo
	int top();

	//Remove o elemento do topo
	void pop();

	//Exibe os elementos do heap
	void show(const std::string& title);

private:

	/* Funcoes privadas que julgar necessarias */

private:
	//Contem os elementos do heap
	std::vector<int> _container;
};

#endif
