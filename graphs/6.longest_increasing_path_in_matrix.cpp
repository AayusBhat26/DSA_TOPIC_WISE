#include <bits/stdc++.h>
using namespace std;
/*
    * problem working explaination:
    1. we need to find the longest increasing path in the matrix
    2. we can consider it like a graph where each cell is a node and there is a directed edge from cell (i, j) to cell (x, y) if matrix[x][y] > matrix[i][j] and (x, y) is adjacent to (i, j)
    3. we can use the concept of topological sorting to find the indegree of each cell, all those cells with indegree 0 would be added to the queue as it would be starting of increasing path
    4. we would perform bfs level order traversal, each level would represent the length of increasing path
    5. at each cell we would reduce the indegree of its adjacent cells which are greater than current cell, if any of those cells indegree becomes 0 we would add it to the queue
    6. finally the number of levels we traversed would be the length of longest increasing path
*/
class Solution
{
public:
    // * directions for up, left, right, down movements
    vector<pair<int, int>> directions = {
        {-1, 0},
        {0, -1},
        {0, 1},
        {1, 0}};
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int maxLength = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> indegreeTracker(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (auto &it : directions)
                {
                    int newi = i + it.first;
                    int newj = j + it.second;
                    // * new cell which is less than current cell would contribute to indegree of current cell
                    if (newi >= 0 && newj >= 0 && newi < n && newj < m && matrix[newi][newj] < matrix[i][j])
                    {
                        indegreeTracker[i][j] += 1;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // * all those cells with indegree 0 would be starting points of increasing path
                if (indegreeTracker[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> currentNode = q.front();
                int x = currentNode.first;
                int y = currentNode.second;
                q.pop();
                for (auto &it : directions)
                {
                    int newx = x + it.first;
                    int newy = y + it.second;
                    if (newx >= 0 && newy >= 0 && newx < n && newy < m && matrix[newx][newy] > matrix[x][y])
                    {
                        indegreeTracker[newx][newy]--;
                        if (indegreeTracker[newx][newy] == 0)
                        {
                            q.push({newx, newy});
                        }
                    }
                }
            }
            maxLength++;
        }
        return maxLength;
    }
};