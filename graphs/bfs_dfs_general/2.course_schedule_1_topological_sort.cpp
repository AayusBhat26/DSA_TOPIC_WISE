#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &p)
    {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(n, 0);
        for (auto &it : p)
        {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            count++;
            // visitng all adjacent nodes
            for (auto &it : graph[currentNode])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return count == n;
    }
};