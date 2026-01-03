#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {

        // Graph: node -> list of (neighbor, weight)
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        vector<bool> visited(V, false);
        vector<int> parent(V, -1);    // MST parent
        vector<int> edgeWeight(V, 0); // weight of edge used to reach node

        // Priority Queue: (weight, node, parent)
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>>
            pq;

        pq.push({0, 0, -1}); // start from node 0
        int sum = 0;

        while (!pq.empty())
        {
            auto [weight, node, p] = pq.top();
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = true;
            sum += weight;
            parent[node] = p;
            edgeWeight[node] = weight;

            for (auto &it : graph[node])
            {
                int neighbourNode = it.first;
                int neighbourWeight = it.second;

                if (!visited[neighbourNode])
                {
                    pq.push({neighbourWeight, neighbourNode, node});
                }
            }
        }

        // --------- OUTPUT MST ---------
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (int v = 0; v < V; v++)
        {
            if (parent[v] != -1)
            {
                cout << parent[v] << " - " << v
                     << " (weight = " << edgeWeight[v] << ")\n";
            }
        }

        cout << "Total weight of MST = " << sum << "\n";

        return sum;
    }
};
