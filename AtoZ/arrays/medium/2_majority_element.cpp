#include <bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &a)
{
    int cand = 0, cnt = 0;
    for (int x : a)
    {
        if (cnt == 0)
        {
            cand = x;
            cnt = 1;
        }
        else if (x == cand)
            cnt++;
        else
            cnt--;
    }
    return cand;
}

int main()
{
    vector<int> a = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(a) << "\n";
    return 0;
}
