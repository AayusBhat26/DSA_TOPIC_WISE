#include <bits/stdc++.h>
using namespace std;
// we need to return the minimum time for a single to reach the entire graph starting from kth node

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> distance(n + 1, INT_MAX);
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto &it : times)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v, w});
        }
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});
        while (!pq.empty())
        {
            pair<int, int> current = pq.top();
            pq.pop();
            int currentDistance = current.first;

            int currentNode = current.second;

            if (currentDistance > distance[currentNode])
                continue;

            for (auto &it : graph[currentNode])
            {
                int neig = it.first;
                int weight = it.second;
                if (currentDistance + weight < distance[neig])
                {
                    distance[neig] = currentDistance + weight;
                    pq.push({distance[neig], neig});
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == INT_MAX)
                return -1;
            res = max(res, distance[i]);
        }
        return res;
    }
};