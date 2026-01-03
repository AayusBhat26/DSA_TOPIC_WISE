#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>distance(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        distance[src] = 0;
        unordered_map<int, vector<pair<int, int>>>graph ;
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            graph[u].push_back({weight, v});
            graph[v].push_back({weight, u});
        }

        while(!pq.empty()){
            pair<int, int> current = pq.top(); pq.pop();
            int currentDistance = current.first;
            int currentNode = current.second;
            if(currentDistance > distance[currentNode]) continue;

            for(auto& it: graph[currentNode]){
                int weight = it.first ;
                int neighbour = it.second;
                if(weight + currentDistance < distance[neighbour]){
                    distance[neighbour] = weight + currentDistance;
                    pq.push({weight + currentDistance, neighbour});
                }
            }
        }
        return distance;
    }
};