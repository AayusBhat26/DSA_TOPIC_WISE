#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(const vector<int> &a, int k)
{
    vector<int> freq(k, 0);
    freq[0] = 1;
    int pref = 0, ans = 0;
    for (int x : a)
    {
        pref = (pref + x) % k;
        if (pref < 0)
            pref += k;
        ans += freq[pref];
        freq[pref]++;
    }
    return ans;
}

int main()
{
    vector<int> a = {4, 5, 0, -2, -3, 1};
    cout << subarraysDivByK(a, 5) << "\n";
    return 0;
}
