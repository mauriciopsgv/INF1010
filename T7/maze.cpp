#include "maze.h"

#include <fstream>
#include <random>
#include <iostream>

#include "unionfind.h"


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
	UnionFind connectedPaths(m*n);

	maze.clear();
	for (int i = 0; i < m*n; i++)
		maze.push_back(true);

	while (connectedPaths.getNumSets() > 1)
	{
		randomWall = randomInt(0, 2 * m*n - 1);
		
		if (randomWall % 2 == 0)
		{
			if (randomWall % (2 * n) == n - 2)
			{
				continue;
			}
			cellA = randomWall / 2;
			cellB = cellA + 1;

		}
		else
		{
			if (randomWall > 2 * n*(m - 1))
			{
				continue;
			}
			cellA = randomWall / 2;
			cellB = cellA + n;
		}

		if (connectedPaths.find(cellA) != connectedPaths.find(cellB))
		{
			maze[randomWall] = 0;
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
