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

	vector<bool> * maze = new vector<bool>();
	createMaze(4, 3, *maze);
	drawMaze(*maze, 4, 3);
	printMaze(*maze);

	vector<bool> * mazeUnit = new vector<bool>();
	createMaze(1, 1, *mazeUnit);
	drawMaze(*mazeUnit, 1, 1);
	printMaze(*mazeUnit);

	vector<bool> * mazeEmpty = new vector<bool>();
	createMaze(0, 0, *mazeEmpty);
	drawMaze(*mazeEmpty, 0, 0);
	printMaze(*mazeEmpty);

	vector<bool> * bigMaze = new vector<bool>();
	createMaze(12, 12, *bigMaze);
	drawMaze(*bigMaze, 12, 12);
	printMaze(*bigMaze);

	return 0;
}