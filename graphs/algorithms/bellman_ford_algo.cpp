#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // distance vector to store the minimum distance from source to other notes
        vector<int> distance(V, 1e8);
        // source to source, distance is zero
        distance[src] = 0;
        // V-1 relaxations
        for (int i = 1; i <= V - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                // can we reach uth node? if yes, did we got a new smaller distance, if  yes update
                if (distance[u] != 1e8 && wt + distance[u] < distance[v])
                {
                    distance[v] = wt + distance[u];
                }
            }
        }

        // one more relaxiation attempt to detect negative cycle
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            // if we are able to update, that means we are in a negative cycle.
            if (distance[u] != 1e8 && w + distance[u] < distance[v])
            {
                return {-1};
            }
        }
        return distance;
    }
};
