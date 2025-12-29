#include <bits/stdc++.h>
using namespace std;

bool isSorted(const vector<int> &a)
{
    for (size_t i = 1; i < a.size(); ++i)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

int main()
{
    vector<int> a = {1, 2, 3, 3, 5};
    cout << isSorted(a) << "\n";
    return 0;
}
