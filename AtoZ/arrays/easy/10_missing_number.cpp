#include <bits/stdc++.h>
using namespace std;

int missingNumber(const vector<int> &a)
{
    int n = a.size();
    int xr = 0;
    for (int i = 0; i <= n; ++i)
        xr ^= i;
    for (int x : a)
        xr ^= x;
    return xr;
}

int main()
{
    vector<int> a = {3, 0, 1};
    cout << missingNumber(a) << "\n";
    return 0;
}
