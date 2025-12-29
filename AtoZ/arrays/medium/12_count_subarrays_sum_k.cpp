#include <bits/stdc++.h>
using namespace std;

int countSubarraySumK(const vector<int> &a, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1;
    int pref = 0, ans = 0;
    for (int x : a)
    {
        pref += x;
        if (freq.count(pref - k))
            ans += freq[pref - k];
        freq[pref]++;
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3};
    cout << countSubarraySumK(a, 3) << "\n";
    return 0;
}
