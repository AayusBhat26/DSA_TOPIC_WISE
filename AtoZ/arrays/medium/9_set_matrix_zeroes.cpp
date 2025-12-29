#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &m)
{
    int n = m.size(), k = m[0].size();
    bool firstRow = false, firstCol = false;
    for (int i = 0; i < n; i++)
        if (m[i][0] == 0)
            firstCol = true;
    for (int j = 0; j < k; j++)
        if (m[0][j] == 0)
            firstRow = true;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < k; j++)
            if (m[i][j] == 0)
                m[i][0] = m[0][j] = 0;
    for (int i = 1; i < n; i++)
        if (m[i][0] == 0)
            for (int j = 1; j < k; j++)
                m[i][j] = 0;
    for (int j = 1; j < k; j++)
        if (m[0][j] == 0)
            for (int i = 1; i < n; i++)
                m[i][j] = 0;
    if (firstRow)
        for (int j = 0; j < k; j++)
            m[0][j] = 0;
    if (firstCol)
        for (int i = 0; i < n; i++)
            m[i][0] = 0;
}

int main()
{
    vector<vector<int>> m = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(m);
    for (auto &r : m)
    {
        for (int x : r)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
