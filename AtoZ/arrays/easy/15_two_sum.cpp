#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &a, int target)
{
    unordered_map<int, int> pos;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        int need = target - a[i];
        if (pos.count(need))
            return {pos[need], i};
        pos[a[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> a = {2, 7, 11, 15};
    auto res = twoSum(a, 9);
    cout << res[0] << ' ' << res[1] << "\n";
    return 0;
}
