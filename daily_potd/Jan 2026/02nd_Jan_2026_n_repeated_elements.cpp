#include <bits/stdc++.h>
using namespace std;

class O1SpaceAndONTIME
{
    int repatedNTimes(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i + 2 < n; i++)
        {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
            {
                return nums[i];
            }
        }
        return nums.back();
    }
};
class ONSpaceandtime
{
public:
    int repeatedNTimes(vector<int> &nums)
    {

        unordered_map<int, int> ump;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ump[nums[i]]++;

            if (ump[nums[i]] == n / 2)
                return nums[i];
        }

        return nums.back();
    }
};