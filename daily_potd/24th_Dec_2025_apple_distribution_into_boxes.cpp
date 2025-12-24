#include <bits/stdc++.h>
using namespace std;
// leetcode 3074

// we have apples and boxes, we need to distribute apples into boxes such that each box gets atmost capacity number of apples
// we need to find the minimum number of boxes required to store all the apples

class Solution
{
public:
    int minimumBoxes(vector<int> &apples, vector<int> &capacity)
    {
        int count = 0;
        // total apples we have
        int sum = accumulate(apples.begin(), apples.end(), 0);
        // we need the minimum of boxes to store all the apples, therefore sorting the array so that we can use the boxes with maximum capacity first
        sort(capacity.begin(), capacity.end());
        // starting from the end as the array is sorted in ascending order
        int n = capacity.size();
        // to track index of capacity array
        int index = n - 1;
        // until we have apples to store i.e. total number of apples > 0
        while (sum > 0)
        {
            sum -= capacity[index];
            count++; // number of boxes used till now
            index--;
        }
        return count;
    }
};