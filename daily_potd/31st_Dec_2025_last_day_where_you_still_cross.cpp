#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>>directions = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };
    bool isPossibleToReachEnd(vector<vector<int>>& cells, int current, int row, int col){
        // creating a grid so that we can mark them land or water
        int n = row;
        int m = col;
        vector<vector<int>>grid(n, vector<int>(m , 0));
        queue<pair<int, int>>q;
        vector<vector<bool>>visited(n, vector<bool>(m , false));


        // toh hum jis day pe hai us day pe kitne cells water se fill ho gye honge
        for(int i = 0; i < current; i++){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        // current land cells hai unh se shuru krenge vo bhi top row se hi
        for(int i = 0 ; i < col; i++){
            if(grid[0][i] == 0){
                q.push({0, i});
                visited[0][i] = true;
            }
        }

        while(!q.empty()){
            auto currentNode = q.front();
            q.pop();
            int currentRow = currentNode.first;
            int currentCol = currentNode.second;
            if(currentRow == row-1) return true;
            for(auto& direction: directions){
                int newRow = currentRow + direction.first;
                int newCol = currentCol + direction.second;
                if(newRow >= 0 && newCol >= 0 && newRow < row && newCol < col && grid[newRow][newCol] == 0 && !visited[newRow][newCol]){
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        /*
            if we are able to cross on Day - D, then we would able to cross on D- 1, D- 2, etc days
            and if we are not able to corss on Day - D, then we won't be able to cross on D + 1, D + 2, etc. days
            we can apply binary search on answer
            where the low = 1(day 1), high = row * column (since each day one cell is flooded, therefore in worst case, in n * m days, all cells are flooded)

            we are given number of rows and columns and a 2d vector which stores the land pairs
            so when we are doing bfs, we need to buil that grid first
        */

        int low = 1;
        int high = row * col;
        int possibleDay = 0;
        while(low <= high){
            int mid = low +(high - low)/ 2;
            // if it is possible to reach the last cell of the matrix with the current possible day, but we need to check if the future days are also possible or not
            if(isPossibleToReachEnd(cells, mid, row, col)){
                possibleDay =mid;
                low = mid + 1;
            }
            else{
                high = mid - 1 ;
            }
        }
        return possibleDay;
    }
};