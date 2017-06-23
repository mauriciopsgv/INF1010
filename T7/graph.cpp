#include "graph.h"
#include "unionfind.h"
#include <iostream>
#include <queue>

Graph::Graph( int N )
    : G(std::vector< std::vector<Edge> >(N))
{

}


void Graph::insertEdge( int from, int to, int weight, bool undirected )
{
    G[from].push_back(Edge({to, weight}));

    if( undirected )
    {
        G[to].push_back(Edge({from, weight}));
    }
}


void Graph::print()
{
    for( unsigned int u = 0; u < G.size(); u++ )
    {
        std::cout << u << ": ";

        if( !G[u].empty() )
        {
            std::cout << G[u][0].v << '(' << G[u][0].w << ')';
        }

        for( unsigned int e = 1; e < G[u].size(); e++ )
        {
            std::cout << ", " << G[u][e].v << '(' << G[u][e].w << ')';
        }

        std::cout << std::endl;
    }
}


void Graph::bfs( int s )
{
	std::queue<int> executionQueue;
	std::vector<Color> colors;

	distances.clear();
	for (int i = 0; i < G.size(); i++)
	{
		colors.push_back(WHITE);
		distances.push_back(1000000);
	}

	executionQueue.push(s);
	colors[s] = GRAY;
	distances[s] = 0;

	while (executionQueue.size() != 0)
	{
		int v = executionQueue.front();
		executionQueue.pop();

		std::cout << v << " ";

		colors[v] = BLACK;

		for (int i = 0; i < G[v].size(); i++)
		{
			int nextV = G[v][i].v;
			if (colors[nextV] == WHITE)
			{
				executionQueue.push(nextV);
				distances[nextV] = distances[v] + 1;
				colors[nextV] = GRAY;
			}
		}
	}
	std::cout << std::endl;
}


void Graph::dfs(int s)
{
}


void Graph::djikstra( int s )
{
}


Graph Graph::kruskal()
{
    return Graph(G.size());
}


bool Graph::isBicolored()
{
    return false;
}

