#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>> &m)
{
    int top = 0, left = 0, bottom = m.size() - 1, right = m[0].size() - 1;
    vector<int> res;
    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
            res.push_back(m[top][j]);
        top++;
        for (int i = top; i <= bottom; i++)
            res.push_back(m[i][right]);
        right--;
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                res.push_back(m[bottom][j]);
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                res.push_back(m[i][left]);
            left++;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto r = spiralOrder(m);
    for (int x : r)
        cout << x << ' ';
    return 0;
}
