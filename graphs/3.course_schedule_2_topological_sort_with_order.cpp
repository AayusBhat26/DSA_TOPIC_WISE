#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>res;
        vector<int>indegree(n, 0);
        queue<int>q;
        unordered_map<int, vector<int>>graph;
        int count = 0;
        for(auto& it: p){
            int u = it[0];
            int v = it[1];
            // we need to take course v first then we can take course u
            graph[v].push_back(u);
            indegree[u]++;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            count++;
            res.push_back(currentNode);
            for(auto& it: graph[currentNode]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(n == count) return res;
        return {};
    }
};