#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(const vector<int> &a)
{
    vector<int> res;
    int mx = INT_MIN;
    for (int i = (int)a.size() - 1; i >= 0; --i)
    {
        if (a[i] >= mx)
        {
            mx = a[i];
            res.push_back(a[i]);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> a = {16, 17, 4, 3, 5, 2};
    auto r = leaders(a);
    for (int x : r)
        cout << x << ' ';
    return 0;
}
