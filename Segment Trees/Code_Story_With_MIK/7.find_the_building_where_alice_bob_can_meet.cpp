#include<bits/stdc++.h>
using namespace std;

// RMIQ + Binary search
class SegmentTree
{
private:
    int n;
    vector<int> sgtree;

public:
    SegmentTree(int n)
    {
        this->n = n;
        sgtree.resize(4 * n);
    }
    SegmentTree(vector<int> &heights, int size) : SegmentTree(size)
    {
        // root node, start, end, heights
        build(0, 0, n - 1, heights);
    }
    void build(int node, int start, int end, vector<int> &heights)
    {
        if (start == end)
        {
            sgtree[node] = start;
            return;
            // leaf node condition
        }

        int mid = start + (end - start) / 2;

        build(2 * node + 1, start, mid, heights);
        build(2 * node + 2, mid + 1, end, heights);
        sgtree[node] = (heights[sgtree[2 * node + 1]] >= heights[sgtree[2 * node + 2]] ? sgtree[2 * node + 1] : sgtree[2 * node + 2]);
    }

    int query(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int node, vector<int> &heights)
    {
        if (segmentStart > queryEnd || segmentEnd < queryStart)
        {
            return -1; // we cannot have any building where alice and bob can meet;
        }
        // overalap: query overlaps segment
        if (segmentStart >= queryStart && segmentEnd <= queryEnd)
        {
            return sgtree[node];
        }

        int mid = segmentStart + (segmentEnd - segmentStart) / 2;

        int leftIndex = query(queryStart, queryEnd, segmentStart, mid, 2 * node + 1, heights);
        int rightIndex = query(queryStart, queryEnd, mid + 1, segmentEnd, 2 * node + 2, heights);

        if (leftIndex == -1)
        {
            return rightIndex;
        }
        if (rightIndex == -1)
        {
            return leftIndex;
        }

        return ((heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex);
    }
    int rangeMaximumIndexQuery(int start, int end, vector<int> &heights)
    {
        // query start, query end, segment start, segment end, root node, heights
        return query(start, end, 0, n - 1, 0, heights);
    }
};
class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        SegmentTree st(heights, n);
        vector<int> res;
        for (auto &query : queries)
        {
            int alice = min(query[1], query[0]);
            int bob = max(query[1], query[0]);

            int left = bob + 1;
            int right = n - 1;
            int resIndex = INT_MAX;
            if (alice == bob || heights[alice] < heights[bob])
            {
                res.push_back(bob);
                continue;
            }
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                int index = st.rangeMaximumIndexQuery(left, mid, heights);

                if (heights[index] > max(heights[alice], heights[bob]))
                {
                    right = mid - 1;
                    resIndex = min(resIndex, index);
                }
                else
                {
                    left = mid + 1;
                }
            }
            if (resIndex == INT_MAX)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(resIndex);
            }
        }
        return res;
    }
};
/*
code is giving wrong output when
1. both the indices are equal (alice == bob)
2. height[bob] > height[alice]

and the code is giving -1 as output for these cases, but the real should be:
1. just push the height of alice or bob any of them as they are equal
2. push the height of bob

so in both the cases we can directly push the bob
*/