#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
        {
            return;
        }

        if (rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if (rank[parent_y] > rank[parent_x])
        {
            parent[parent_x] = parent_y;
        }
        else
        {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int krushkal(vector<vector<int>> &graph)
    {
        int sum = 0;
        for (auto &it : graph)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v)
            {
                sum += wt;
                Union(u, v);
            }
        }
        return sum;
    }
    int spanningTree(int V, vector<vector<int>> &edges)
    {

        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        // GFG mai iski zaroort nhi hai kyuki edges mai already sab given hai, but for learning purposes, we need this. 
        vector<vector<int>> graph;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph.push_back({u, v, wt});
        }

        auto comp = [&](vector<int> &a, vector<int> &b)
        {
            return a[2] < b[2];
        };

        sort(begin(graph), end(graph), comp);

        return krushkal(graph);
    }
};