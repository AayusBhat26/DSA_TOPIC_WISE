#include <bits/stdc++.h>
using namespace std;

long long mergeCount(vector<int> &a, int l, int r)
{
    if (l >= r)
        return 0;
    int m = l + (r - l) / 2;
    long long ans = mergeCount(a, l, m) + mergeCount(a, m + 1, r);
    int j = m + 1;
    for (int i = l; i <= m; i++)
    {
        while (j <= r && (long long)a[i] > 2LL * a[j])
            j++;
        ans += (j - (m + 1));
    }
    vector<int> temp;
    temp.reserve(r - l + 1);
    int i = l;
    j = m + 1;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }
    while (i <= m)
        temp.push_back(a[i++]);
    while (j <= r)
        temp.push_back(a[j++]);
    for (int k = 0; k < (int)temp.size(); k++)
        a[l + k] = temp[k];
    return ans;
}

long long reversePairs(vector<int> a)
{
    return mergeCount(a, 0, (int)a.size() - 1);
}

int main()
{
    vector<int> a = {1, 3, 2, 3, 1};
    cout << reversePairs(a) << "\n";
    return 0;
}
