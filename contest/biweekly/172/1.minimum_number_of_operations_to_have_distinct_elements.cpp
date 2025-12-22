#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_set<int> ust;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (ust.count(nums[i]))
            {
                return i / 3 + 1;
            }
            ust.insert(nums[i]);
        }
        return 0;
    }
};