#include <bits/stdc++.h>
using namespace std;
/*
 * we need to find the minimum effort required to reach the end of the matrix starting from 0, 0 of matrix
 * effort = abs(heights[x][y] - heights[newx][newy])
 * the difference between two adjacent nodes is the weight between two nodes
 */

class Solution
{
public:
    // 4 directions
    vector<pair<int, int>> directions = {
        {0, -1},
        {1, 0},
        {-1, 0},
        {0, 1}};
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        // declaring a priority queue to store the pairs
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // pushing the source into the queue
        pq.push({0, {0, 0}});

        int n = heights.size();
        int m = heights[0].size();
        // resultant 2d vector
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        // setting the distance from source to source as 0
        res[0][0] = 0;
        while (!pq.empty())
        {
            // getting the first distance (minimum distance)
            int difference = pq.top().first;
            pair<int, int> currentCoordinate = pq.top().second;
            pq.pop();
            // current coordiantes
            int x = currentCoordinate.first;
            int y = currentCoordinate.second;
            // moving in all 4 directions
            for (auto &it : directions)
            {
                // new x coordinate and new y coordinate
                int newx = x + it.first;
                int newy = y + it.second;
                // checking if it lies in the matrix
                if (newx >= 0 && newy >= 0 && newx < n && newy < m)
                {
                    // get the difference
                    int absDifference = abs(heights[x][y] - heights[newx][newy]);
                    // current difference
                    int maxDifference = max(difference, absDifference);
                    // if the current difference is less than the previously store difference, store the current difference into the resultant vector
                    if (res[newx][newy] > maxDifference)
                    {
                        res[newx][newy] = maxDifference;
                        // push into the queue
                        pq.push({maxDifference, {newx, newy}});
                    }
                }
            }
        }
        // this is the goal to reach
        return res[n - 1][m - 1];
    }
};