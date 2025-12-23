#include <bits/stdc++.h>
using namespace std;
/*
Disjoint Set Union (DSU) or Union-Find Data Structure

1. every set has a representative (or parent)
*/

class DSU
{
private:
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void union_sets(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX == parentY)
        {
            return;
        }

        if (rank[parentX] > rank[parentY])
        {
            // x's parent would become the parent of y' parent
            parent[parentY] = parentX;
        }
        else if (rank[parentX] < rank[parentY])
        {
            // y's parent would become the parent of x's parent
            parent[parentX] = parentY;
        }
        else
        {
            // equal ranks:
            // 1. update parents
            // 2. increment ranks
            parent[parentY] = parentX;
            rank[parentX] += 1;
        }
    }
};