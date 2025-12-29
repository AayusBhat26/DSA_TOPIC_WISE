#include <bits/stdc++.h>
using namespace std;

int longestEqual01(const vector<int> &a)
{
    unordered_map<int, int> pos;
    pos[0] = -1;
    int pref = 0, best = 0;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        pref += (a[i] == 1 ? 1 : -1);
        if (pos.count(pref))
            best = max(best, i - pos[pref]);
        else
            pos[pref] = i;
    }
    return best;
}

int main()
{
    vector<int> a = {0, 0, 1, 0, 1, 1, 0};
    cout << longestEqual01(a) << "\n";
    return 0;
}
