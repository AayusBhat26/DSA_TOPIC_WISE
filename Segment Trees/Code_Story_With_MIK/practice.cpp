#include<bits/stdc++.h>
using namespace std;

class segmentTree{
    private:
    int n;
    vector<int>tree;

    public:
    segmentTree(int n){
        this->n = n;
        tree.resize(4 * n);

    }
    segmentTree(int size, int arr[]): segmentTree(size){
        buildTree(0, 0, size-1, arr);
    }

    void buildTree(int node, int start, int end, int arr[]){
        if(start == end){
            tree[node] = arr[start];
        }

        int mid = start + (end - start) / 2;

        buildTree(2 * node + 1, start, mid, arr);
        buildTree(2 * node + 2, mid + 1, end, arr);
    }
    int merge(int first, int second){
        return first + second ;
    }

    int query (int queryStart, int queryEnd, int segmentStart, int segmentEnd, int node){
        // segment out of the query range
        if(queryEnd < segmentStart || queryEnd > segmentStart){
            return 0;
        }
        // query overlaps the segment
        if(segmentStart >= queryStart && segmentEnd <= queryEnd){
            return tree[node];
        }

        int mid = segmentStart + (segmentEnd - segmentStart) / 2;

        query(queryStart, queryEnd, segmentStart, mid, 2 * node + 1) +
        query(queryStart, queryEnd, mid + 1, segmentEnd, 2 * node + 2);

        return merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
};