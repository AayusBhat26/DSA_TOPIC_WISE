#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    int n;
    vector<int> sgtree;
    SegmentTree(int n)
    {
        this->n = n;
        sgtree.resize(4 * n, 0);
    }

    // constructing the segment tree
    SegmentTree(const vector<int> &nums)
    {
        this->n = nums.size();
        sgtree.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    int merge(int leftNode, int rightNode)
    {
        return leftNode + rightNode;
    }
    void build(const vector<int> &nums, int node, int start, int end)
    {
        // base case
        if (start == end)
        {
            sgtree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);

        sgtree[node] = merge(sgtree[2 * node + 1], sgtree[2 * node + 2]);
    }

    void update(int node, int start, int end, int index, int value){
        if (start == end){
            sgtree[node] = value;
            return ;
        }
        int mid = (start + end) / 2;

        if(index <= mid ){
            update(2 * node + 1, start, mid, index, value);
        }
        else{
            update(2 * node + 2, mid + 1, end, index, value);
        }

        sgtree[node] = merge(sgtree[2 * node + 1], sgtree[2 * node + 2]);
    }

    void update(int index, int value){
        update(0, 0, n-1, index, value);
    }
};