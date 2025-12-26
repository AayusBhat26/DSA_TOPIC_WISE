#include <bits/stdc++.h>
using namespace std;
/*
    * how to build:

    * 1. declare the n and vector for storing vaue
    * 2. declare two constructor, one for assigning the size, and other for calling the build function
    * declare and define build function
        i. if the left and right are equal, we have reached the leaf node, so assign the node index with arr[left] value and return
        ii. calculate the mid value
        iii. recursively call build function for left and right child
        iv. assign the tree array in index node with the required value (here sum)

    * 3. build the query function
        i. query is completely outside the segment => return 0
        ii. query overlaps the segment => return tree[node]
        iii. calculate mid
        iv. recursively call on left and right children

*/

class segmentTree
{
private:
    int n;
    vector<int> tree;

public:
    segmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n);
    }

    segmentTree(int arr[], int size) : segmentTree(size)
    {
        build(0, arr, 0, size - 1);
    }
    int merge(int leftNode, int rightNode){
        return leftNode + rightNode;
    }
    void build(int node, int arr[], int left, int right)
    {

        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(2 * node + 1, arr, left, mid);
        build(2 * node + 2, arr, mid + 1, right);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // note: query overlaps segment
    int query(int node, int queryStart, int queryEnd, int segmentStart, int segmentEnd)
    {
        // no overlap
        if (queryEnd < segmentStart || queryStart > segmentEnd)
        {
            return 0;
        }

        // overlap: query overlaps segment
        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
        {
            return tree[node];
        }

        int mid = segmentStart + (segmentEnd - segmentStart) / 2;

        return query(2 * node + 1, queryStart, queryEnd, segmentStart, mid) + query(2 * node + 2, queryStart, queryEnd, mid + 1, segmentEnd);
    }
};

class Solution
{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        segmentTree s(arr, n);

        vector<int> res;

        for (int i = 0; i < 2 * q; i += 2)
        {
            int start = queries[i] - 1;
            int end = queries[i + 1] - 1;

            res.push_back(s.query(0, start, end, 0, n - 1));
        }

        return res;
    }
};