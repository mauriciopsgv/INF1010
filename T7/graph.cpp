#include "graph.h"
#include "unionfind.h"
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <functional>

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
	for (unsigned int i = 0; i < G.size(); i++)
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

		for (unsigned int i = 0; i < G[v].size(); i++)
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
	std::vector<Color> colors;

	distances.clear();
	for (unsigned int i = 0; i < G.size(); i++)
		colors.push_back(WHITE);
	
	dfs_rec(s, colors);

	std::cout << std::endl;
}

void Graph::dfs_rec( int s, std::vector<Color>& colors )
{
	colors[s] = GRAY;
	std::cout << s << " ";

	for (unsigned int i = 0; i < G[s].size(); i++)
	{
		int nextV = G[s][i].v;
		if (colors[nextV] == WHITE)
			dfs_rec(nextV, colors);
	}
}

class minHeapDjikstraComparator
{
	public:
		bool operator() (std::pair<int, int> const lpair, std::pair<int, int> const rpair) const
		{
			return lpair.second > rpair.second;
		}
};

void Graph::djikstra( int s )
{
	std::vector<int> pred;
	std::vector<Color> colors;
	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, minHeapDjikstraComparator> minHeap;

	distances.clear();
	for (unsigned int i = 0; i < G.size(); i++)
	{
		colors.push_back(WHITE);
		distances.push_back(1000000);
		pred.push_back(-1);
	}

	distances[s] = 0;
	minHeap.push(*new std::pair<int, int>(s, 0));

	while (minHeap.size() != 0)
	{
		int u = minHeap.top().first;
		minHeap.pop();
		for (unsigned int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i].v;
			if (colors[v] == WHITE)
			{
				int w = G[u][i].w;
				int newDist = distances[u] + w;
				if (newDist < distances[v])
				{
					distances[v] = newDist;
					minHeap.push(*new std::pair<int, int>(v, newDist));
					pred[v] = u;
				}
			}
		}
		colors[u] = BLACK;
	}
}

class minHeapKruskalComparator
{
	public:
		bool operator() (std::tuple<int, int, int> const ltuple, std::tuple<int, int, int> const rtuple) const
		{
			return  std::get<2>(ltuple) > std::get<2>(rtuple);
		}
};

Graph Graph::kruskal()
{
	Graph newGraph(G.size());
	UnionFind nodes(G.size());
	std::priority_queue<std::tuple<int,int,int>, std::vector<std::tuple<int,int,int>>, minHeapKruskalComparator> minHeap;

	for (unsigned int v = 0; v < G.size(); v++)
	{
		for (unsigned int i = 0; i < G[v].size(); i++)
		{
			minHeap.push(*new std::tuple<int, int, int>(v, G[v][i].v, G[v][i].w));
		}
	}

	while (nodes.getNumSets() != 1 && minHeap.size() != 0)
	{
		std::tuple<int, int, int> edge = minHeap.top();
		minHeap.pop();

		if (nodes.find(std::get<0>(edge)) != nodes.find(std::get<1>(edge)))
		{
			int to = std::get<0>(edge);
			int from = std::get<1>(edge);
			int weight = std::get<2>(edge);
			newGraph.G[from].push_back(Edge({ to, weight }));
			newGraph.G[to].push_back(Edge({ from, weight }));
			nodes.makeUnion(to, from);
		}
	}
	

    return newGraph;
}


bool Graph::isBicolored()
{
	Color neighborColor = BLACK;
	std::vector<bool> checked;
	std::queue<int> executionQueue;
	std::vector<Color> colors;

	distances.clear();
	for (unsigned int i = 0; i < G.size(); i++)
		checked.push_back(false);

	for (unsigned int i = 0; i < checked.size(); i++)
	{
		if (checked[i])
			continue;

		colors.clear();
		for (unsigned int i = 0; i < G.size(); i++)
			colors.push_back(GRAY);

		executionQueue.push(i);
		colors[i] = WHITE;

		while (executionQueue.size() != 0)
		{
			int v = executionQueue.front();
			executionQueue.pop();
			checked[v] = true;

			if (colors[v] == WHITE)
				neighborColor = BLACK;
			else
				neighborColor = WHITE;

			for (unsigned int i = 0; i < G[v].size(); i++)
			{
				int neighbor = G[v][i].v;
				if (colors[neighbor] == GRAY)
				{
					executionQueue.push(neighbor);
					colors[neighbor] = neighborColor;
				}
				else if (colors[neighbor] != neighborColor)
				{
					return false;
				}
			}
		}
	}

	return true;
}