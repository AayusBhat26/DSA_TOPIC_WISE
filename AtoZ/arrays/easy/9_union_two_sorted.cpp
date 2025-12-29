#include <bits/stdc++.h>
using namespace std;

vector<int> unionSorted(const vector<int> &a, const vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    while (i < n || j < m)
    {
        int val;
        if (j == m || (i < n && a[i] < b[j]))
            val = a[i++];
        else if (i == n || b[j] < a[i])
            val = b[j++];
        else
        {
            val = a[i];
            i++;
            j++;
        }
        if (res.empty() || res.back() != val)
            res.push_back(val);
    }
    return res;
}

int main()
{
    vector<int> a = {1, 2, 2, 3};
    vector<int> b = {2, 3, 4};
    auto res = unionSorted(a, b);
    for (int x : res)
        cout << x << ' ';
    return 0;
}
