#include <bits/stdc++.h>
using namespace std;
// we have to count the number of negative elements in grid and grid's row is sorted
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = m - 1;
            int possible = -1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (grid[i][mid] >= 0)
                {
                    left = mid + 1;
                }
                else
                {
                    possible = mid;
                    right = mid - 1;
                }
            }
            if (possible != -1)
            {
                res += m - possible;
            }
        }
        return res;
    }
};