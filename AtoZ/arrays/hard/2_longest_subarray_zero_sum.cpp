#include <bits/stdc++.h>
using namespace std;

int longestZeroSum(const vector<int> &a)
{
    unordered_map<int, int> first;
    int pref = 0, best = 0;
    first[0] = -1;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        pref += a[i];
        if (first.count(pref))
            best = max(best, i - first[pref]);
        else
            first[pref] = i;
    }
    return best;
}

int main()
{
    vector<int> a = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    cout << longestZeroSum(a) << "\n";
    return 0;
}
