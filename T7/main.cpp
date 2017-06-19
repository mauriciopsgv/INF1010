 #include <iostream>

#include "unionfind.h"

#define UFSIZE 5

using namespace std;

int main(void)
{
	UnionFind * uf = new UnionFind(5);

	for (int i = 0; i < UFSIZE; i++)
	{
		cout << "Representante de " << i << " eh " << uf->find(i) << endl;
	}

	uf->makeUnion(3, 4);
	uf->makeUnion(2, 3);
	uf->makeUnion(1, 5);
	uf->makeUnion(0, 1);
	uf->makeUnion(1, 1);
	uf->makeUnion(-1, 5);
	uf->makeUnion(4, 6);

	for (int i = 0; i < UFSIZE; i++)
	{
		cout << "Representante de " << i << " eh " << uf->find(i) << endl;
	}

	return 0;
}