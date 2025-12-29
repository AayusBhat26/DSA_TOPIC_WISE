#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            long sum = (long)nums[i] + nums[l] + nums[r];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[l], nums[r]});
                int a = nums[l], b = nums[r];
                while (l < r && nums[l] == a)
                    l++;
                while (l < r && nums[r] == b)
                    r--;
            }
            else if (sum < 0)
                l++;
            else
                r--;
        }
    }
    return res;
}

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    auto r = threeSum(a);
    for (auto &t : r)
    {
        for (int x : t)
            cout << x << ' ';
        cout << '|';
    }
    return 0;
}
