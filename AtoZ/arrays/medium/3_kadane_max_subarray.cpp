#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &a)
{
    int best = INT_MIN, cur = 0;
    for (int x : a)
    {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

int main()
{
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(a) << "\n";
    return 0;
}
