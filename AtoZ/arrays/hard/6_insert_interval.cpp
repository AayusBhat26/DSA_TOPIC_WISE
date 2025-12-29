#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> iv, vector<int> nw)
{
    vector<vector<int>> res;
    int i = 0, n = iv.size();
    while (i < n && iv[i][1] < nw[0])
        res.push_back(iv[i++]);
    while (i < n && iv[i][0] <= nw[1])
    {
        nw[0] = min(nw[0], iv[i][0]);
        nw[1] = max(nw[1], iv[i][1]);
        i++;
    }
    res.push_back(nw);
    while (i < n)
        res.push_back(iv[i++]);
    return res;
}

int main()
{
    vector<vector<int>> iv = {{1, 3}, {6, 9}};
    auto r = insertInterval(iv, {2, 5});
    for (auto &v : r)
    {
        cout << '[' << v[0] << ',' << v[1] << "] ";
    }
    return 0;
}
