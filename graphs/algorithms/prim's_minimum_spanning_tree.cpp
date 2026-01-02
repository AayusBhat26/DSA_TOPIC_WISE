#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // code here
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> visited(V, false);

        int sum = 0;

        pq.push({0, 0}); // weight and node
        // note: we do not set the visited[0] as true, because we haven't visited it yet.

        while (!pq.empty())
        {
            pair<int, int> currentPair = pq.top();
            pq.pop();

            int weight = currentPair.first;
            int node = currentPair.second;

            if (visited[node])
                continue;

            sum += weight;
            visited[node] = true;

            for (auto &it : graph[node])
            {

                int neigbour = it.first;
                int neigbourWeight = it.second;

                if (!visited[neigbour])
                {
                    pq.push({neigbourWeight, neigbour});
                }
            }
        }
        return sum;
    }
};