#include <fstream>
#include <random>
#include <iostream>

#include "unionfind.h"
#include "graph.h"
#include "maze.h"

using namespace std;

int randomInt( int from, int to )
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(from, to);
    return distr(generator);
}


void createMaze( int m, int n, std::vector< bool >& maze )
{
	int randomWall, cellA, cellB;
	int rows = n;
	int columns = m;
	UnionFind connectedPaths(rows*columns);

	maze.clear();
	for (int i = 0; i < 2* rows*columns; i++)
		maze.push_back(true);

	while (connectedPaths.getNumSets() > 1)
	{
		randomWall = randomInt(0, 2 * rows*columns - 1);
		
		if (randomWall % 2 == 0)
		{
			if ( (randomWall + 2) % (2 * columns) == 0)
			{
				continue;
			}
			cellA = randomWall / 2;
			cellB = cellA + 1;

		}
		else
		{
			if (randomWall > 2 * columns*(rows - 1))
			{
				continue;
			}
			cellA = randomWall / 2;
			cellB = cellA + columns;
		}

		if (connectedPaths.find(cellA) != connectedPaths.find(cellB))
		{
			maze.at(randomWall) = false;
			connectedPaths.makeUnion(cellA, cellB);
		}

	}



}


void drawMaze( const std::vector< bool >& maze, int m, int n )
{
    //Linha de cima
    std::cout << "+";
    for( int j = 0; j < m; j++ )
        std::cout << "---+";

    for( int i = 0; i < n; i++ )
    {
        int pos = i*2*m;
        std::cout << std::endl << "|";
        for( int j = 0; j < m; j++ )
        {
            std::cout << "   ";
            std::cout << (maze[pos] ? "|" : " ");
            pos+=2;
        }
        std::cout << std::endl << "+";

        pos=i*2*m+1;
        for( int j = 0; j < m; j++ )
        {
            std::cout << (maze[pos] ? "---" : "   ") << "+";
            pos+=2;
        }
    }

    std::cout<< std::endl;
}


void printMaze( const std::vector< bool >& maze )
{
    if( !maze.empty() )
    {
        for( size_t i = 0; i < maze.size()-1; i+=2 )
        {
            std::cout << i/2 << " "
                      << (maze[i+0] ? 1 : 0) << " "
                      << (maze[i+1] ? 1 : 0) << std::endl;
        }
    }
}

Graph createGraph(const std::vector<bool>& maze, int m, int n)
{
	int size = m*n;
	Graph mazeGraph(size);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int cell1 = i*m + j;
			if (!maze[cell1 * 2] && (cell1 + 1) % m != 0)
				mazeGraph.insertEdge(cell1, cell1 + 1);
			if (!maze[cell1 * 2 + 1] && cell1<(size - m))
				mazeGraph.insertEdge(cell1, cell1 + m);
		}
	}
	return mazeGraph;
}


void findStartEnd(const std::vector<bool>& maze, int m, int n, int& start, int& end)
{
	//Cria o grafo que representa o labirinto
	Graph mazeGraph = createGraph(maze, m, n);

	//TODO: Encontrar entrada e saida
}
