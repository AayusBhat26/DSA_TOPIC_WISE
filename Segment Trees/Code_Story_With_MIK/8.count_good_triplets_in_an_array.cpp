#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // we are updating segment tree's leaf node with 1's when we see the element
    // when we get a query of a range, then we are adding them accordingly
    void updateSegmentTree(int i, int l, int r, int updateIndex, vector<long long> &segmentTree)
    {
        // when we reached the leaf, we would update the node's val;ue to 1 as we want to mark it as visited and eventually it would help counting the number of common elements on the left of the current index
        if (l == r)
        {
            segmentTree[i] = 1;
            return;
        }
        // finding the mid
        int mid = l + (r - l) / 2;
        // the index that is needed to be updated is present on the left hand side
        if (updateIndex <= mid)
        {
            updateSegmentTree(2 * i + 1, l, mid, updateIndex, segmentTree);
        }
        // the index that is needed to be updated is oresent on the right hand side
        else
        {
            updateSegmentTree(2 * i + 2, mid + 1, r, updateIndex, segmentTree);
        }
        // update the current node when their parent is updated as we have done a recursion - leap of faith call
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    // querying the segment tree to the sum of number of elements
    long long querySegmentTree(int queryStart, int queryEnd, int i, int l, int r, vector<long long> &segmentTree)
    {
        // if current query is outside the segment range
        if (r < queryStart || l > queryEnd)
        {
            return 0;
        }
        // when overlapping happens
        if (l >= queryStart && r <= queryEnd)
        {
            return segmentTree[i];
        }
        // calculating the mid
        int mid = l + (r - l) / 2;
        // moving to the left and right.
        long long left = querySegmentTree(queryStart, queryEnd, 2 * i + 1, l, mid, segmentTree);
        long long right = querySegmentTree(queryStart, queryEnd, 2 * i + 2, mid + 1, r, segmentTree);
        // returning the count of elements from left and right
        return left + right;
    }

    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(); // size of the array
        // map to store the element and index of second array so that we can get the index in O(1) time when we are doing the range thing
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums2[i]] = i;
        }
        // segment tree array declaration
        vector<long long> segmentTree(4 * n);
        // for storing the count of triplets
        long long result = 0;

        // update the tree with the first element of first array and passing the index of first element's index in second array
        updateSegmentTree(0, 0, n - 1, mp[nums1[0]], segmentTree);
        // we are done with the first element of the first array
        // we would start with second element
        for (int i = 1; i < n; i++)
        {
            // getting the index of first array's element from second array
            int idx = mp[nums1[i]];
            // left count, number of common elements on the left of 2nd array's index.
            long long leftCommonCount = querySegmentTree(0, idx, 0, 0, n - 1, segmentTree);
            // not valid elements
            long long leftNotCommonCount = i - leftCommonCount;
            // elements on the right of current element from first array in the second array
            long long elementsAfterIdxNums2 = (n - 1) - idx;
            // right common count, we need to subtract the invalid (or that count which is invalid in the left)
            long long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
            result += leftCommonCount * rightCommonCount;
            // update the segment tree so that we make mark the index as visited which would envetually help in counting the number of common elements.
            updateSegmentTree(0, 0, n - 1, idx, segmentTree);
        }

        return result;
    }
};

/*
            1. both of the arrays are the permutation of numbers from 1 to n - 1, where n is the size of the array
            2. a good triplet is a set of 3 distinct values which are present in increasing order by position both in numms 1 and nums2
            3. return total number of good triplets


            pick triplets from  nums1 so that their index is increasing order, now we need to check if the picked elements from nums1 do they have indices in increasing order or not

            in the first example
            nums1 = {2, 0, 1, 3}
            nums2 = {0, 1, 2, 3}

            let us select 3 elements from nums1 as 2 0 1 and indices => 0, 1, 2
            in nums2, the indices of 2, 0 and 1 are 2, 0, 1,
            here, indices do not follow

            another example: elements from nums1 => 0 1 3 => indices => 1, 2, 3 => indices in increasing order
            now, elements from nums2 => 0, 1, 3 => indices => 0, 1, 2 => indices in increasing order
        */