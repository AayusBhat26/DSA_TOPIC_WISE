#include <bits/stdc++.h>
using namespace std;

long long mergeCount(vector<int> &a, int l, int r)
{
    if (l >= r)
        return 0;
    int m = l + (r - l) / 2;
    long long inv = mergeCount(a, l, m) + mergeCount(a, m + 1, r);
    vector<int> temp;
    temp.reserve(r - l + 1);
    int i = l, j = m + 1;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
        {
            temp.push_back(a[j++]);
            inv += (m - i + 1);
        }
    }
    while (i <= m)
        temp.push_back(a[i++]);
    while (j <= r)
        temp.push_back(a[j++]);
    for (int k = 0; k < (int)temp.size(); k++)
        a[l + k] = temp[k];
    return inv;
}

long long countInversions(vector<int> a)
{
    return mergeCount(a, 0, (int)a.size() - 1);
}

int main()
{
    vector<int> a = {2, 4, 1, 3, 5};
    cout << countInversions(a) << "\n";
    return 0;
}
