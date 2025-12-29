#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(const vector<int> &nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : nums)
    {
        if (!s.count(x - 1))
        {
            int cur = x, len = 1;
            while (s.count(cur + 1))
            {
                cur++;
                len++;
            }
            best = max(best, len);
        }
    }
    return best;
}

int main()
{
    vector<int> a = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(a) << "\n";
    return 0;
}
