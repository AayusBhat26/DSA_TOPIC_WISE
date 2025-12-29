#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int j = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] != a[j - 1])
            a[j++] = a[i];
    return j;
}

int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(a);
    for (int i = 0; i < k; ++i)
        cout << a[i] << ' ';
    return 0;
}
