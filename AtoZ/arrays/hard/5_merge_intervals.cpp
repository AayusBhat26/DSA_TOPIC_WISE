#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> iv)
{
    if (iv.empty())
        return {};
    sort(iv.begin(), iv.end());
    vector<vector<int>> res;
    res.push_back(iv[0]);
    for (size_t i = 1; i < iv.size(); ++i)
    {
        if (iv[i][0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], iv[i][1]);
        else
            res.push_back(iv[i]);
    }
    return res;
}

int main()
{
    vector<vector<int>> iv = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto r = mergeIntervals(iv);
    for (auto &v : r)
    {
        cout << '[' << v[0] << ',' << v[1] << "] ";
    }
    return 0;
}
