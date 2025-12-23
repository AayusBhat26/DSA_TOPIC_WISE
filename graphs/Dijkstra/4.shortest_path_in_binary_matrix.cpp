#include <bits/stdc++.h>
using namespace std;

// in this question we need to find the shortest path from top-left to bottom-right in a binary matrix where 0's are valid cells and 1's are blocked cells

class Solution
{
public:
    // 8 directions
    vector<pair<int, int>> directions = {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0},
        {1, 1},
        {-1, 1},
        {1, -1},
        {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        // we are allowed to move when we are on 0's only
        if (n == 0 || m == 0 || grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
        {
            return -1;
        }
        // initially push the source node into the queue
        q.push({0, 0});
        grid[0][0] = 1; // mark as visited
        int level = 0;  // to keep track of levels
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto currentNode = q.front();
                q.pop();
                int row = currentNode.first;
                int col = currentNode.second;
                if (row == n - 1 && col == m - 1)
                    return level + 1;
                for (auto &it : directions)
                {
                    int newrow = it.first + row;
                    int newcol = it.second + col;
                    if (newrow >= 0 && newcol >= 0 && newrow < n && newcol < m && grid[newrow][newcol] == 0)
                    {
                        // we can visit our adjcancet node
                        q.push({newrow, newcol});
                        grid[newrow][newcol] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};