#include <bits/stdc++.h>
using namespace std;

int secondLargest(const vector<int> &a)
{
    int mx = INT_MIN, second = INT_MIN;
    for (int x : a)
    {
        if (x > mx)
        {
            second = mx;
            mx = x;
        }
        else if (x != mx && x > second)
        {
            second = x;
        }
    }
    return second;
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 5};
    cout << secondLargest(a) << "\n";
    return 0;
}
