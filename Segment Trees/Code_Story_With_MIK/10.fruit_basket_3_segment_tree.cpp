#include <bits/stdc++.h>
using namespace std;

/*
we will find the maximum from ranges, if a particular range's maximum is smaller than the required capacity, then we would move to right (since we moved to left first).

the max node from which we will take, we mark it as -1 so that in future no one gets the access to it as asked in the question.

for different ranges, we need maximum of that range

root would represent the entire capacity array maximum that would be populated when we come back from the recursion.

- leaf node will contain single elements
- parent of leaf node will contain the maximum of their children
- when we assign the fruits to a basket, we return true
- when we reach a node where we can assign the fruits and we check if the left and right child of that node is greater than current fruit's count, if it is not we return false, else we continue asigning and returning true.
*/

class Solution
{
public:
    int n;
    vector<int> segmentTree;
    int merge(int first, int second)
    {
        return first > second ? first : second;
    }
    void build(int node, int left, int right, vector<int> &baskets)
    {
        if (left == right)
        {
            // reached leaf node
            segmentTree[node] = baskets[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(2 * node + 1, left, mid, baskets);
        build(2 * node + 2, mid + 1, right, baskets);
        segmentTree[node] = merge(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);
    }
    // can we assign the fruit to the capacity ?
    bool query(int left, int right, int node, int value)
    {
        if (segmentTree[node] < value)
        {
            return false;
        }

        if (left == right)
        {
            // we have reached the root node, now we can assign the value so we mark it as -1
            segmentTree[node] = -1;
            return true;
        }

        int mid = left + (right - left) / 2;
        bool possible = false;
        // left child value greater  than or equal to current value
        if (segmentTree[2 * node + 1] >= value)
        {
            possible = query(left, mid, 2 * node + 1, value);
        }
        // right child value greater than or equal to current value
        if (!possible && segmentTree[2 * node + 2] >= value)
        {
            possible = query(mid + 1, right, 2 * node + 2, value);
        }

        segmentTree[node] = merge(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);

        return possible;
    }
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        this->n = baskets.size();

        segmentTree.resize(4 * n, -1);
        // root node, left, right, basket (as we need to find the maximum from the basket only)
        build(0, 0, n - 1, baskets);

        int unplaced = 0;
        for (int &fruit : fruits)
        {
            // current fruit's count is placeable or not
            if (!query(0, 0, n - 1, fruit))
            {
                unplaced++;
            }
        }
        return unplaced;
    }
};