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
    return (parent[u] == -1) ? u : find(u);
}


void UnionFind::makeUnion(int u, int v)
{
}


int UnionFind::getNumSets()
{
    return numSets;
}
