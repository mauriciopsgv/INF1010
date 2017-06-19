 #include <iostream>

#include "unionfind.h"
#include "maze.h"

#define UFSIZE 5

using namespace std;

int main(void)
{
	UnionFind * uf = new UnionFind(5);

	for (int i = 0; i < UFSIZE; i++)
	{
		cout << "Representante de " << i << " eh " << uf->find(i) << endl;
	}

	cout << "Temos " << uf->getNumSets() << " conjuntos" << endl;

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

	cout << "Temos " << uf->getNumSets() << " conjuntos" << endl;


	cout << endl << endl << "VAMOS CRIAR O LABIRINTO" << endl;

	vector<bool> maze;
	createMaze(3, 4, maze);
	drawMaze(maze, 3, 4);

	return 0;
}