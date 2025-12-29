#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int> &a, int target)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] == target)
            return i;
    return -1;
}

int main()
{
    vector<int> a = {5, 3, 2, 4, 1};
    cout << linearSearch(a, 4) << "\n";
    return 0;
}
