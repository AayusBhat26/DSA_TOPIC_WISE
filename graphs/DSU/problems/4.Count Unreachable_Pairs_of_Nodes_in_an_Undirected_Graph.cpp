#include <bits/stdc++.h>
using namespace std;

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
        if (x == parent[x])
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionSets(int x, int y)
    {
        int parentx = find(x);
        int parenty = find(y);
        if (parentx == parenty)
            return;

        if (rank[parentx] > rank[parenty])
        {
            parent[parenty] = parentx;
        }
        else if (rank[parentx] < rank[parenty])
        {
            parent[parentx] = parenty;
        }
        else
        {
            parent[parentx] = parenty;
            rank[parenty]++;
        }
    }
};

class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        DSU *d = new DSU(n);
        // number of components
        long long remaining = n;
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            // union of all components which are connected to have separate components
            d->unionSets(u, v);
        }
        // counting the number of children for each parent
        map<int, int> childrenCount;
        for (int i = 0; i < n; i++)
        {
            int parent = d->find(i); // finding the parent of current node
            childrenCount[parent]++;
        }
        // resultant, for each component and it's elements in it, number of possible unreachable pair
        long long res = 0;
        for (auto &it : childrenCount)
        {
            // number of elements in a component
            long long currentParentChildrenCount = it.second;
            // for each component, the number of other components would be unreachable
            res += currentParentChildrenCount * (remaining - currentParentChildrenCount);
            // we are done with current component and it's number of elements
            remaining -= currentParentChildrenCount;
        }
        return res;
    }
};