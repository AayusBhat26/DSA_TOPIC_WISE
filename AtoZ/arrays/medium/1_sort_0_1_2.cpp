#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &a)
{
    int l = 0, m = 0, r = a.size() - 1;
    while (m <= r)
    {
        if (a[m] == 0)
            swap(a[l++], a[m++]);
        else if (a[m] == 1)
            m++;
        else
            swap(a[m], a[r--]);
    }
}

int main()
{
    vector<int> a = {2, 0, 2, 1, 1, 0};
    sort012(a);
    for (int x : a)
        cout << x << ' ';
    return 0;
}
