#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(const vector<int> &a, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1;
    int xr = 0, ans = 0;
    for (int x : a)
    {
        xr ^= x;
        int need = xr ^ k;
        if (freq.count(need))
            ans += freq[need];
        freq[xr]++;
    }
    return ans;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    cout << subarraysWithXorK(a, 6) << "\n";
    return 0;
}
