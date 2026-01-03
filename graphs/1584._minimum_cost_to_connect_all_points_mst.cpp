#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mst(unordered_map<int, vector<pair<int, int>>> &graph, int V)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0});

        int sum = 0;

        vector<bool> visited(V, false);

        while (!pq.empty())
        {
            pair<int, int> currentPair = pq.top();
            pq.pop();
            int weight = currentPair.first;
            int currentNode = currentPair.second;

            if (visited[currentNode])
            {
                continue;
            }
            sum += weight;
            visited[currentNode] = true;
            for (auto &it : graph[currentNode])
            {
                int neigbour = it.first;
                int wt = it.second;

                if (!visited[neigbour])
                {
                    pq.push({wt, neigbour});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        int V = points.size();
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int distance = abs((x1 - x2)) + abs((y1 - y2));

                graph[i].push_back({j, distance});
                graph[j].push_back({i, distance});
            }
        }
        return mst(graph, V);
    }
};