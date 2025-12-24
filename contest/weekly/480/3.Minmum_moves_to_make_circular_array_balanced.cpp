#include <bits/stdc++.h>
using namespace std;

// we need to find the number of moves (minimum) required to make a circular array balanced i.e. every element is non negative
// in my operation we can move exactly 1 unit of balance either to the left or to the right
// we are also given that we can have at most one negative element in the array.
/*
* idea:

1. since we are assured that we could have at most 1 negative element in the array, we can first find the index of that negative element, if it does not exists, we can return 0 i.e. we do not need to make any moves

2. once we have the index, we can start from 0th index and calculate the distance between the first negative element and current element from left or right because we are asked to consider the array as circular, we can move to the back of the array from the first index itself,

3. intial requirement would be of absolute value of negative element.

4. we would calculate 2 distances from the negative element to the current element, those are left distance and right distance, left distance is the circular distance moving from current element to the negative element and right distance would be the distance from current element to negative element moving towards right.

5. take the minimum of both the distances and we push the {distance, balance} into vector so that we can keep a track of all the distances and balances.

6. finally we would sort the vector based on distance and start fulfilling the requirements from minimum distance to maximum distance until we have balance to fulfill the requirements.
*/

class Solution
{
public:
    long long minMoves(vector<int> &balance)
    {
        long long totalSum = accumulate(balance.begin(), balance.end(), 0LL);
        int firstNeg = -1;
        int n = balance.size();
        for (int i = 0; i < n; i++)
        {
            if (balance[i] < 0)
            {
                firstNeg = i;
                break;
            }
            // totalSum += balance[i];
        }

        if (totalSum < 0)
            return -1;

        if (firstNeg == -1)
            return 0;

        long long required = abs((long long)balance[firstNeg]);

        vector<pair<int, int>> distanceAndSource;

        for (int i = 0; i < n; i++)
        {
            if (balance[i] > 0)
            {
                int distance = abs(i - firstNeg);
                int circular = n - distance;
                int minimumDistance = min(distance, circular);
                distanceAndSource.push_back({minimumDistance, balance[i]});
            }
        }

        sort(distanceAndSource.begin(), distanceAndSource.end());
        long long res = 0;

        for (auto &it : distanceAndSource)
        {
            int distance = it.first;
            int amt = it.second;
            long long possible = min((long long)amt, required);
            res += possible * distance;
            required -= possible;

            if (required == 0)
                break;
        }

        return res;
    }
};