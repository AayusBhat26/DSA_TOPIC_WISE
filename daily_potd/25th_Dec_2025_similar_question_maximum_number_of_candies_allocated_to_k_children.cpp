#include <bits/stdc++.h>
using namespace std;

/*
 * we are supposed to find the maximum amount of candies to be allocated to each children by making portions
 * based on the description of the problem, we can use binary search on answers
 * 1. we want to maximize a numeric value (candies per children)
 * 2. there is a clear range between 0 to maximum element from the array for each candy that can be allocated to each children
 */

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int res = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long currentPortionsSum = 0;
            for (int candy : candies)
            {
                currentPortionsSum += (candy / mid);
            }

            if (currentPortionsSum >= k)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;
        /*

            5 8 6, k = 3
            low = 1
            high = 8

            1. mid = 4

            total portion => 1 2 1 => 4, possbile answer, but we want maximum, so we move towards right i.e. low = mid + 1
            low = 5, high = 8
            mid = 6

            total portion => 0, 1, 1 => 2, not possible as k == 3, so we decrease our high, high = mid - 1;

            low = 5, high = 5
            mid = 5

            total portion => 1, 1, 1= 3, possible answer

        */
    }
};