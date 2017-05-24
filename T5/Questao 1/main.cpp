#include <iostream>
#include "mod2_lista5.h"

using namespace std;

int main(void)
{
	Heap heapTeste;
	heapTeste.push(6);
	//heapTeste.show("Add 6");
	heapTeste.push(2);
	//heapTeste.show("Add 2");
	heapTeste.push(4);
	//heapTeste.show("Add 4");
	heapTeste.push(7);
	//heapTeste.show("Add 7");
	heapTeste.push(12);
	//heapTeste.show("Add 12");
	heapTeste.push(1);
	heapTeste.show("Heap Original");


	int values[6] = { 2, 6, 4, 12, 3 };
	Heap * heapCopiaValores = new Heap(values, 5);

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

	Heap * heapCopiaHeap = new Heap(heapTeste);
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