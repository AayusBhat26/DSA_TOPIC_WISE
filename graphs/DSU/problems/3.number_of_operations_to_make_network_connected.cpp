#include<bits/stdc++.h>
using namespace std;

class DSU{
    private:
    vector<int>parent, rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void unionSets(int x, int y){
        int parentx = find(x);
        int parenty = find(y);
        if(parentx == parenty) return ;
        if(rank[parentx] > rank[parenty]){
            parent[parenty] = parentx;
        }
        else if(rank[parenty] > rank[parentx]){
            parent[parentx] = parenty;
        }
        else{
            parent[parenty] = parentx;
            rank[parentx]++;
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections){
        /*
            we need to return the number of edges we need to deattach and attach in such a way that we have an entirely connected network.
            for that we can simply check how many components can we make after merging all the neigbours
            and after that we return res - 1, where res is the number of components and we are substracting 1 because between 2 components we can have 1 edge
        */
       DSU* d = new DSU(n);
       int res = n ; // number of edges we need to add initially
       if(connections.size() < n-1){
        return -1;
       }
       for(auto& it: connections){
        if(d->find(it[0]) != d->find(it[1])){
            res--;
            d->unionSets(it[0], it[1]);
        }
       }
       return res - 1; 
    }
};