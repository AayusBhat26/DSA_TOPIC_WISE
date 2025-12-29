#include <bits/stdc++.h>
using namespace std;

int largest(const vector<int> &a)
{
    return *max_element(a.begin(), a.end());
}

int main()
{
    vector<int> a = {1, 5, 3, 9, 2};
    cout << largest(a) << "\n";
    return 0;
}
