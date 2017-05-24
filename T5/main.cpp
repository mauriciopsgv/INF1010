#include <iostream>
#include "mod2_lista5.h"

using namespace std;

int main(void)
{
	cout << "------ Heap Normal ------" << endl << endl;

	Heap<double> heapTeste;
	heapTeste.push(6.2);
	heapTeste.show("Add 6");
	heapTeste.push(2.1);
	heapTeste.show("Add 2");
	heapTeste.push(4.4);
	heapTeste.show("Add 4");
	heapTeste.push(7.6);
	heapTeste.show("Add 7");
	heapTeste.push(12.3);
	heapTeste.show("Add 12");
	heapTeste.push(1.6);
	heapTeste.show("Heap Original");

	cout << endl;

	cout << "The size of this heap is " << heapTeste.size() << endl;
	cout << "The element in the top is " << heapTeste.top() << endl;

	cout << endl;

	heapTeste.show("Pop");
	heapTeste.pop();
	heapTeste.show("Pop");
	heapTeste.pop();
	heapTeste.show("Pop");
	heapTeste.pop();
	heapTeste.show("Pop");
	heapTeste.pop();

	cout << endl << endl << "------ Heap Para ser Copiado ------" << endl << endl;

	Heap<float> heapParaSerCopiado;
	heapParaSerCopiado.push(6);
	heapParaSerCopiado.push(2);
	heapParaSerCopiado.push(4);
	heapParaSerCopiado.push(7);
	heapParaSerCopiado.push(12);
	heapParaSerCopiado.push(1);

	heapParaSerCopiado.show("Heap me copia");

	cout << endl << endl << "------ Heap Copiado com Valores ------" << endl << endl;

	std::vector<float> values;
	values.push_back(2);
	values.push_back(6);
	values.push_back(4);
	values.push_back(12);
	values.push_back(3);
	Heap<float> * heapCopiaValores = new Heap<float>(values);

	heapCopiaValores->show("Heap copiado");
	heapCopiaValores->push(7);
	heapCopiaValores->show("Add 7");
	heapCopiaValores->push(1);
	heapCopiaValores->show("Add 1");

	cout << endl;

	cout << "The size of this heap is " << heapCopiaValores->size() << endl;
	cout << "The element in the top is " << heapCopiaValores->top() << endl;

	cout << endl;

	heapCopiaValores->pop();
	heapCopiaValores->show("Pop");
	heapCopiaValores->pop();
	heapCopiaValores->show("Pop");
	heapCopiaValores->pop();
	heapCopiaValores->show("Pop");
	heapCopiaValores->pop();
	heapCopiaValores->show("Pop");
	heapCopiaValores->pop();

	cout << endl << endl << "------ Heap Copiado de Heap ------" << endl << endl;

	Heap<float> * heapCopiaHeap = new Heap<float>(heapParaSerCopiado);
	heapCopiaHeap->show("Heap copiado de Heap");
	heapCopiaHeap->push(5);
	heapCopiaHeap->show("Add 5");
	heapCopiaHeap->push(0);
	heapCopiaHeap->show("Add 0");

	cout << endl;

	cout << "The size of this heap is " << heapCopiaHeap->size() << endl;
	cout << "The element in the top is " << heapCopiaHeap->top() << endl;

	cout << endl;

	heapCopiaHeap->pop();
	heapCopiaHeap->show("Pop");
	heapCopiaHeap->pop();
	heapCopiaHeap->show("Pop");
	heapCopiaHeap->pop();
	heapCopiaHeap->show("Pop");
	heapCopiaHeap->pop();
	heapCopiaHeap->show("Pop");
	heapCopiaHeap->pop();

	return 0;
}