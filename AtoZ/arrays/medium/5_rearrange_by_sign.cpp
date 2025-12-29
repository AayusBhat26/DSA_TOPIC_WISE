#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeBySign(const vector<int> &a)
{
    vector<int> pos, neg;
    for (int x : a)
        (x >= 0 ? pos : neg).push_back(x);
    vector<int> res;
    res.reserve(a.size());
    size_t i = 0, j = 0;
    while (i < pos.size() || j < neg.size())
    {
        if (i < pos.size())
            res.push_back(pos[i++]);
        if (j < neg.size())
            res.push_back(neg[j++]);
    }
    return res;
}

int main()
{
    vector<int> a = {3, 1, -2, -5, 2, -4};
    auto r = rearrangeBySign(a);
    for (int x : r)
        cout << x << ' ';
    return 0;
}
