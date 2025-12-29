#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(const vector<int> &a)
{
    int best = 0, cur = 0;
    for (int x : a)
    {
        if (x == 1)
        {
            cur++;
            best = max(best, cur);
        }
        else
            cur = 0;
    }
    return best;
}

int main()
{
    vector<int> a = {1, 1, 0, 1, 1, 1};
    cout << maxConsecutiveOnes(a) << "\n";
    return 0;
}
