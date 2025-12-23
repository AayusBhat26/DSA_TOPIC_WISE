#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1}); // node = 1 as source

        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({w, v});
            graph[v].push_back({w, u});
        }
        vector<int> parent(n + 1); // for nth node, parent needs to be stored
        // initially all the parents are parents of themselves only
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        vector<int> distance(n + 1, INT_MAX);
        distance[1] = 0;
        while (!pq.empty())
        {
            pair<int, int> current = pq.top();
            pq.pop();
            int currentDistance = current.first;
            int currentNode = current.second;

            if (currentDistance > distance[currentNode])
                continue;

            // neigbours
            for (auto &it : graph[currentNode])
            {
                int weight = it.first;
                int neighbour = it.second;
                if (currentDistance + weight < distance[neighbour])
                {
                    pq.push({currentDistance + weight, neighbour});
                    distance[neighbour] = currentDistance + weight;
                    parent[neighbour] = currentNode;
                }
            }
        }
        int node = n;
        if (distance[node] == INT_MAX)
            return {-1};
        vector<int> res;
        while (parent[node] != node)
        {
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(1);
        reverse(res.begin(), res.end());

        vector<int> finalResult;
        finalResult.push_back(distance[n]);
        for (int vertex : res)
        {
            finalResult.push_back(vertex);
        }
        return finalResult;
    }
};