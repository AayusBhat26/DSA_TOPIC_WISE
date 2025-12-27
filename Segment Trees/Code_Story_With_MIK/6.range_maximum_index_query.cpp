#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
private:
    int n;
    vector<int> sgtree;

public:
    segmentTree(int n)
    {
        this->n = n;
        sgtree.resize(4 * this->n);
    }
    segmentTree(vector<int> &nums, int size) : segmentTree(size)
    {
        build(0, 0, n - 1, nums);
    }
    void build(int node, int start, int end, vector<int> &nums)
    {
        if (start == end)
        {
            sgtree[node] = start;
            return;
        }

        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);
        sgtree[node] = (nums[sgtree[2 * node + 1]] >= nums[sgtree[2 * node + 2]] ? sgtree[2 * node + 1] : sgtree[2 * node + 2]);
    }
    int query(int querystart, int queryend, int segmentstart, int segmentend, int node, vector<int> &nums)
    {
        if (segmentstart > queryend || segmentend < querystart)
        {
            // out of range
            return -1;
        }

        if (segmentstart >= querystart && segmentend <= queryend)
        {
            return sgtree[node];
        }

        int mid = segmentstart + (segmentend - segmentstart) / 2;
        int leftIndex = query(querystart, queryend, segmentstart, mid, 2 * node + 1, nums);

        int rightIndex = query(querystart, queryend, mid + 1, segmentend, 2 * node + 2, nums);

        if (leftIndex == -1)
        {
            return rightIndex;
        }
        if (rightIndex == -1)
        {
            return leftIndex;
        }

        return (nums[leftIndex] >= nums[rightIndex] ? leftIndex : rightIndex);
    }
    int RangeMaximumIndexQuery(vector<int> &nums, int querystart, int queryend)
    {
        return query(querystart, queryend, 0, n - 1, 0, nums);
    }
};
class Solution
{
public:
    vector<int> rangeMaximumIndexQuery(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> res;
        segmentTree st(nums, n);
        for (auto &query : queries)
        {
            int start = query[0];
            int end = query[1];

            int index = st.RangeMaximumIndexQuery(nums, start, end);
            res.push_back(index);
        }
        return res;
    }
};