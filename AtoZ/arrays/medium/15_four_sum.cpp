#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            long long tgt = (long long)target - nums[i] - nums[j];
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                long long sum = nums[l] + nums[r];
                if (sum == tgt)
                {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    int a = nums[l], b = nums[r];
                    while (l < r && nums[l] == a)
                        l++;
                    while (l < r && nums[r] == b)
                        r--;
                }
                else if (sum < tgt)
                    l++;
                else
                    r--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> a = {1, 0, -1, 0, -2, 2};
    auto r = fourSum(a, 0);
    for (auto &q : r)
    {
        for (int x : q)
            cout << x << ' ';
        cout << '|';
    }
    return 0;
}
