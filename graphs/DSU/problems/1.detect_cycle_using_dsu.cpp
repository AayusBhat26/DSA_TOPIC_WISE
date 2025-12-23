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
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y)
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
            rank[parenty] += 1;
        }
    }
};
class Solution
{
public:
    int detectCycle(int V, vector<int> adj[])
    {
        DSU *d = new DSU(V);
        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                // if we have alread done with 0 -> 1 then why do 1 -> 0
                if (u < v)
                {
                    // if the parent of neighbour and current node are equal, then it is a cycle
                    if (d->find(u) == d->find(v))
                    {
                        return true;
                    }
                    // if parent are not equal, make their parent equal.
                    else
                    {
                        d->unionSet(u, v);
                    }
                }
            }
        }
        return false;
    }
};