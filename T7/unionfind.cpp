#include "unionfind.h"


UnionFind::UnionFind(int n)
    : parent( std::vector<int>(n, -1) )
    , size( std::vector<int>(n, 1) )
    , numSets(n)
{
}


UnionFind::~UnionFind()
{
}


int UnionFind::find(int u)
{
    return (parent[u] == -1) ? u : find(parent[u]);
}


void UnionFind::makeUnion(int u, int v)
{
	if (u == v ||
		u < 0  || u >= (int) parent.size() || 
		v < 0  || v >= (int) parent.size() )
		return;

	int aux;
	int repU = find(u);
	int repV = find(v);
	if (repU == repV)
		return;

	size[repU] += size[repV];
	size[repV] = 0;

	while (parent[v] != -1)
	{
		aux = v;
		v = parent[v];
		parent[aux] = repU;
	}
	parent[v] = repU;
}


int UnionFind::getNumSets()
{
    return numSets;
}
