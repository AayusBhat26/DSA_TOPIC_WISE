#include <bits/stdc++.h>
using namespace std;

void leftRotateOne(vector<int> &a)
{
    if (a.empty())
        return;
    int first = a.front();
    for (size_t i = 1; i < a.size(); ++i)
        a[i - 1] = a[i];
    a.back() = first;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    leftRotateOne(a);
    for (int x : a)
        cout << x << ' ';
    return 0;
}
