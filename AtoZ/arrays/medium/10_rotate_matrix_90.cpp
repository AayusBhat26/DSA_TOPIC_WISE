#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &m)
{
    int n = m.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(m[i][j], m[j][i]);
    for (auto &row : m)
        reverse(row.begin(), row.end());
}

int main()
{
    vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate90(m);
    for (auto &r : m)
    {
        for (int x : r)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
