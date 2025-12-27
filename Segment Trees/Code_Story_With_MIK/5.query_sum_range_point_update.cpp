#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    int n;
    // segment tree
    vector<int> sgtree;
    // merge function to return the sum of the left and right children of a node
    int merge(int first, int second)
    {
        return first + second;
    }
    // building the segment tree
    void buildTree(int node, int left, int right, vector<int> &nums)
    {
        // if we reached the leaf node
        if (left == right)
        {
            sgtree[node] = nums[left];
            return;
        }
        // moving to left and right children
        int mid = left + (right - left) / 2;
        buildTree(2 * node + 1, left, mid, nums);
        buildTree(2 * node + 2, mid + 1, right, nums);
        sgtree[node] = merge(sgtree[2 * node + 1], sgtree[2 * node + 2]);
    }
    NumArray(vector<int> &nums)
    {
        this->n = nums.size();
        sgtree.resize(4 * n);
        buildTree(0, 0, n - 1, nums);
    }

    void update(int node, int start, int end, int index, int value)
    {
        if (start == end)
        {
            sgtree[node] = value;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid)
        {
            update(2 * node + 1, start, mid, index, value);
        }
        else
        {
            update(2 * node + 2, mid + 1, end, index, value);
        }
        sgtree[node] = sgtree[2 * node + 1] + sgtree[2 * node + 2];
    }
    int query(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int node)
    {
        if (segmentStart > queryEnd || segmentEnd < queryStart)
        {
            return 0;
        }

        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
        {
            return sgtree[node];
        }
        int mid = segmentStart + (segmentEnd - segmentStart) / 2;
        return query(queryStart, queryEnd, segmentStart, mid, 2 * node + 1) +
               query(queryStart, queryEnd, mid + 1, segmentEnd, 2 * node + 2);
    }
    void update(int index, int val)
    {
        // node, left, right, index to update, value
        update(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */