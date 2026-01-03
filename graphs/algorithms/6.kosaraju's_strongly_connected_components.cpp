#include <bits/stdc++.h>
using namespace std;
// Position this line where user code will be pasted.
class Solution
{
public:
    void dfs_fill(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node] = true;

        for (int &v : adj[node])
        {
            if (!visited[v])
            {
                dfs_fill(v, visited, st, adj);
            }
        }
        // phele mere baache daalo phir merko daalo stack mai
        st.push(node);
    }

    void dfs_traversal(int node, vector<bool> &visited, vector<vector<int>> &adj)
    {
        visited[node] = true;

        for (int &v : adj[node])
        {
            if (!visited[v])
            {
                dfs_traversal(v, visited, adj);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        stack<int> st;
        int V = adj.size();
        vector<bool> visited(V, false);
        // filling the stack for the order
        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                dfs_fill(u, visited, st, adj);
            }
        }

        // reversing the nodes

        vector<vector<int>> adjReversed(V);
        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                adjReversed[v].push_back(u);
            }
        }
        int countofSCC = 0; // count of strongly connected components
        visited = vector<bool>(V, false);
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                dfs_traversal(node, visited, adjReversed);
                countofSCC++;
            }
        }
        return countofSCC;
    }
};