#include <bits/stdc++.h>
using namespace std;
// given n nodes and edges, check whether the given graph is valid tree or not
/*
    for a valud tree:
    1. it should be acyclic (checked using dfs)
    2. it should be fully connected (checked using visited array, all nodes should be visited after dfs starting from 0th node with parent as -1)
    3. it should have exactly n-1 edges (we can check this before proceeding to dfs and return false if edges.size() != n-1)
*/
class Solution
{
public:
    bool dfs(int node, int parent, unordered_map<int, vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;
        for (int neig : graph[node])
        {
            if (!visited[neig])
            {
                if (!dfs(neig, node, graph, visited))
                    return false;
            }
            // already visited but it is not a parent
            else if (neig != parent)
                return false; // cycle is present therefiore not valid
        }
        // cyucle is not present therefore valid
        return true;
    }
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // a graph is a valid tree iff it is acyclic, full connected and exactly n-1 edges
        if (edges.size() != n - 1)
            return false;
        unordered_map<int, vector<int>> graph;
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        // node, parent
        if (!dfs(0, -1, graph, visited))
        {
            return false;
        }

        // did we visited all the nodes -> full connected or not
        for (bool it : visited)
        {
            if (!it)
                return false;
        }
        return true;
    }
};
