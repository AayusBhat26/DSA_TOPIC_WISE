#include <bits/stdc++.h>
using namespace std;

void leftRotateD(vector<int> &a, int d)
{
    int n = a.size();
    if (!n)
        return;
    d %= n;
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    leftRotateD(a, 2);
    for (int x : a)
        cout << x << ' ';
    return 0;
}
