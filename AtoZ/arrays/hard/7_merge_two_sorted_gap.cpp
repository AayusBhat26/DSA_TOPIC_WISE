#include <bits/stdc++.h>
using namespace std;

void mergeGap(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    auto gap = [&](int g)
    { return g <= 1 ? 0 : (g + 1) / 2; };
    for (int g = gap(n + m); g > 0; g = gap(g))
    {
        int i = 0, j = g;
        while (j < n + m)
        {
            int &x = (i < n) ? a[i] : b[i - n];
            int &y = (j < n) ? a[j] : b[j - n];
            if (x > y)
                swap(x, y);
            i++;
            j++;
        }
    }
}

int main()
{
    vector<int> a = {1, 4, 7, 8, 10};
    vector<int> b = {2, 3, 9};
    mergeGap(a, b);
    for (int x : a)
        cout << x << ' ';
    for (int x : b)
        cout << x << ' ';
    return 0;
}
