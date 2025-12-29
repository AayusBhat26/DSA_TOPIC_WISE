#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> frequency(const vector<int> &a)
{
    unordered_map<int, int> freq;
    for (int x : a)
        freq[x]++;
    return freq;
}

int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 3};
    auto f = frequency(a);
    for (auto &p : f)
        cout << p.first << ':' << p.second << ' ';
    return 0;
}
