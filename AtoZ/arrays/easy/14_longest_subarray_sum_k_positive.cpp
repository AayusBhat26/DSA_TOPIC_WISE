#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumK(const vector<int> &a, int k)
{
    int n = a.size();
    int l = 0, r = 0, sum = 0, best = 0;
    while (r < n)
    {
        sum += a[r];
        while (l <= r && sum > k)
            sum -= a[l++];
        if (sum == k)
            best = max(best, r - l + 1);
        r++;
    }
    return best;
}

int main()
{
    vector<int> a = {1, 2, 1, 1, 1, 2, 3};
    cout << longestSubarraySumK(a, 3) << "\n";
    return 0;
}
