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
        // we have reached the single index, so we just add the element
        if (start == end)
        {
            sgtree[node] = nums[start];
            return;
        }
        // finding the mid
        int mid = (start + end) / 2;
        // move to the left child
        build(nums, 2 * node + 1, start, mid);
        // move to right child
        build(nums, 2 * node + 2, mid + 1, end);
        // merging the children and building the parent node
        sgtree[node] = merge(sgtree[2 * node + 1], sgtree[2 * node + 2]);
    }
    // update query
    void update(int node, int start, int end, int index, int value)
    {
        // we have reached the required index i.e. the index we want to update
        if (start == end)
        {
            sgtree[node] = value;
            return;
        }
        // finding the mid
        int mid = (start + end) / 2;
        // index is present in the left subtree
        if (index <= mid)
        {
            update(2 * node + 1, start, mid, index, value);
        }
        // index is present in the right subtree
        else
        {
            update(2 * node + 2, mid + 1, end, index, value);
        }
        // we have reached after recursion calls, so we update the parent.
        sgtree[node] = merge(sgtree[2 * node + 1], sgtree[2 * node + 2]);
    }
    int query(int segmentStart, int segmentEnd, int queryStart, int queryEnd, int node)
    {
        if (queryEnd < segmentStart || segmentEnd < queryStart)
        {
            // out of range
            return 0;
        }
        // overlap: query overlaps the query
        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
        {
            return sgtree[node];
        }
        int mid = segmentStart + (segmentEnd - segmentStart) / 2;

        return query(segmentStart, mid, queryStart, queryEnd, 2 * node + 1) +
               query(mid + 1, segmentEnd, queryStart, queryEnd, 2 * node + 2);
    }
    // wrapper or calling function for build
    void update(int index, int value)
    {
        update(0, 0, n - 1, index, value);
    }
};