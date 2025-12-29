#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &a)
{
    int pos = 0;
    for (int x : a)
        if (x != 0)
            a[pos++] = x;
    while (pos < (int)a.size())
        a[pos++] = 0;
}

int main()
{
    vector<int> a = {0, 1, 0, 3, 12};
    moveZeros(a);
    for (int x : a)
        cout << x << ' ';
    return 0;
}
