#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int ans = nums[0], curMin = nums[0], curMax = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i)
    {
        if (nums[i] < 0)
            swap(curMin, curMax);
        curMax = max(nums[i], curMax * nums[i]);
        curMin = min(nums[i], curMin * nums[i]);
        ans = max(ans, curMax);
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 3, -2, 4};
    cout << maxProduct(a) << "\n";
    return 0;
}
