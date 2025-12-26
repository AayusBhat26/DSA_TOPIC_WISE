#include <bits/stdc++.h>
using namespace std;

/*
it refers to update a range in segment tree with a given value
we use lazy tree and segment tree arrays
*/

class SegmentTree
{
private:
    int n;
    vector<int> segmentTree, lazyTree;

public:
    SegmentTree(int n)
    {
        this->n = n;
        this->segmentTree.resize(4 * n, 0);
        this->lazyTree.resize(4 * n, 0);
    }

    SegmentTree(const vector<int> &nums, int size) : SegmentTree(size)
    {
        build(0, 0, size - 1, nums);
    }
    int merge(int first, int second)
    {
        return first + second;
    }
    void build(int node, int left, int right, const vector<int> &nums)
    {
        if (left == right)
        {
            segmentTree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build(2 * node + 1, left, mid, nums);
        build(2 * node + 2, mid + 1, right, nums);
        segmentTree[node] = merge(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);
    }

    void updateRange(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int node, int value)
    {
        // lazy tree contains some value, first update that in the segment tree
        if (lazyTree[node] != 0)
        {
            segmentTree[node] += (segmentEnd - segmentStart + 1) * lazyTree[node];

            // propagate the node's lazy array value to its children
            if (segmentEnd != segmentStart)
            {
                // this means that it is not a leaf node
                lazyTree[2 * node + 1] += lazyTree[node];
                lazyTree[2 * node + 2] += lazyTree[node];
            }
            // reset the value once used
            lazyTree[node] = 0;
        }

        // invalid and out of range
        if (queryEnd < segmentStart || queryStart > segmentEnd || segmentStart > segmentEnd)
        {
            return;
        }

        // overlapping: query overlaps segment
        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
        {
            segmentTree[node] += (segmentEnd - segmentStart + 1) * value;

            // add the value to the chidlren of current node in the lazy tree
            if (segmentStart != segmentEnd)
            {
                lazyTree[2 * node + 1] += value;
                lazyTree[2 * node + 2] += value;
            }

            return;
        }
        int mid = segmentStart + (segmentEnd - segmentStart) / 2;

        updateRange(queryStart, queryEnd, segmentStart, mid, 2 * node + 1, value);
        updateRange(queryStart, queryEnd, mid + 1, segmentEnd, 2 * node + 2, value);
        segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
    }

    int queryRange(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int node)
    {
        // Apply pending lazy updates first
        if (lazyTree[node] != 0)
        {
            segmentTree[node] += (segmentEnd - segmentStart + 1) * lazyTree[node];

            if (segmentStart != segmentEnd)
            {
                lazyTree[2 * node + 1] += lazyTree[node];
                lazyTree[2 * node + 2] += lazyTree[node];
            }
            lazyTree[node] = 0;
        }

        // No overlap or invalid range
        if (queryEnd < segmentStart || queryStart > segmentEnd || segmentStart > segmentEnd)
        {
            return 0;
        }

        // Complete overlap
        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
        {
            return segmentTree[node];
        }

        // Partial overlap
        int mid = segmentStart + (segmentEnd - segmentStart) / 2;
        int leftSum = queryRange(queryStart, queryEnd, segmentStart, mid, 2 * node + 1);
        int rightSum = queryRange(queryStart, queryEnd, mid + 1, segmentEnd, 2 * node + 2);

        return leftSum + rightSum;
    }
};