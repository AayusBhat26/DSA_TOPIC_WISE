#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &prices)
{
    int mn = INT_MAX, best = 0;
    for (int p : prices)
    {
        mn = min(mn, p);
        best = max(best, p - mn);
    }
    return best;
}

int main()
{
    vector<int> p = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(p) << "\n";
    return 0;
}
