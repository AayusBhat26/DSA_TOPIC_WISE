#include <bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> &a)
{
    int xr = 0;
    for (int x : a)
        xr ^= x;
    return xr;
}

int main()
{
    vector<int> a = {4, 1, 2, 1, 2};
    cout << singleNumber(a) << "\n";
    return 0;
}
