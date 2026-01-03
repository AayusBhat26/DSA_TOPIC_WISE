#include<bits/stdc++.h>
using namespace std;

/*
in this question, we need to count the number of ways to color the grid so that so adjacent colors are equal

we are given a n x 3 grid, where we have n rows and 3 columns,
each cell in a row is supposed to be filled.


*/
class Solution
{
public:
    int MOD = 1e9 + 7;
    int helper(int index, int prev1, int prev2, int prev3, vector<vector<vector<vector<int>>>> &dp)
    {
        if (index == 0)
            return 1;
        if (dp[index][prev1][prev2][prev3] != -1)
        {
            return dp[index][prev1][prev2][prev3];
        }
        long long res = 0;

        for (int color1 = 1; color1 <= 3; color1++)
        {
            if (color1 == prev1)
                continue;

            for (int color2 = 1; color2 <= 3; color2++)
            {
                if (color2 == prev2 || color2 == color1)
                    continue;

                for (int color3 = 1; color3 <= 3; color3++)
                {
                    if (color3 == prev3 || color3 == color2)
                        continue;

                    res = (res + helper(index - 1, color1, color2, color3, dp)) % MOD;
                }
            }
        }
        return dp[index][prev1][prev2][prev3] = res;
    }
    int numOfWays(int n)
    {
        vector<vector<vector<vector<int>>>> dp(5002, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1))));
        return helper(n, 0, 0, 0, dp);
    }
};