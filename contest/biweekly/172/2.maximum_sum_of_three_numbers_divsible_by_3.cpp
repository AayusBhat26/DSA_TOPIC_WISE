#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mod0, mod1, mod2;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 3 == 0)
                mod0.push_back(nums[i]);
            else if (nums[i] % 3 == 1)
                mod1.push_back(nums[i]);
            else
                mod2.push_back(nums[i]);
        }

        sort(mod0.rbegin(), mod0.rend());
        sort(mod1.rbegin(), mod1.rend());
        sort(mod2.rbegin(), mod2.rend());

        int res = 0;
        // case 1: 0, 0, 0
        if (mod0.size() >= 3)
        {
            res = max(mod0[0] + mod0[1] + mod0[2], res);
        }

        // case 2: 1, 1, 1
        if (mod1.size() >= 3)
        {
            res = max(mod1[0] + mod1[1] + mod1[2], res);
        }

        // case 1: 2, 2, 2
        if (mod2.size() >= 3)
        {
            res = max(mod2[0] + mod2[1] + mod2[2], res);
        }

        // case 1: 0, 1, 2
        if (mod0.size() >= 1 && mod1.size() >= 1 && mod2.size() >= 1)
        {
            res = max(mod0[0] + mod1[0] + mod2[0], res);
        }

        return res;
    }
};