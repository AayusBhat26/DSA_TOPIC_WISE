#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mirrorDistance(int n)
    {
        int temp = n;
        int reversed = 0;
        while (temp > 0)
        {
            int rem = temp % 10;
            reversed = reversed * 10 + reversed;
            temp /= 10;
        }

        return abs(n - reversed);
    }
};