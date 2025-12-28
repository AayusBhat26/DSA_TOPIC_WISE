#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int count = 0;
        int n = fruits.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (baskets[j] >= fruits[i])
                {
                    count++;
                    // basket can't have any other fruit once taken
                    baskets[j] = 0;
                    break;
                }
            }
        }

        return n - count;
    }
};