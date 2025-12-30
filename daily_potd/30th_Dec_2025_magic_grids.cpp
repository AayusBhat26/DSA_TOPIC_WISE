#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isMagicGrid(vector<vector<int>> &grid, int r, int c){
        // note:
        /*
            important observation:

            the middle cell is coming in the sum of second row, second column, first and second diagonal

            so we can say that, (sum of 1 to 9 numbers) + 3 * middle cell = 60 (total sum of all 4 )

            45 + 3 * x = 60 => 3 * x = 15 => x = 5

            so this proves that we need to have the middle cell of the current grid as 5, if it not 5, return false
        */
        if (grid[r + 1][c + 1] != 5)
            return false;
        // checking if all the elements of current grid are unique or not
        vector<int> seen(10, 0); // to check the uniqueness
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int currentValue = grid[r + i][c + j];
                if (currentValue < 1 || currentValue > 9 || seen[currentValue] != 0)
                {
                    return false;
                }
                seen[currentValue] = 1;
            }
        }
        // total grid sum would be 45 (SINCE UNIQUE ELEMENTS)
        // so each row should have sum equal to 15 only
        // checking row sums
        for (int i = 0; i < 3; i++)
        {
            if ((grid[r + i][c + 0] + grid[r + i][c + 1] + grid[r + i][c + 2]) != 15)
            {
                return false;
            }
        }

        // checking column sums

        for (int j = 0; j < 3; j++)
        {
            if ((grid[r + 0][c + j] + grid[r + 1][c + j] + grid[r + 2][c + j]) != 15)
            {
                return false;
            }
        }

        // checking diagonal sum

        if ((grid[r + 0][c + 0] + grid[r + 1][c + 1] + grid[r + 2][c + 2]) != 15)
            return false;
        if ((grid[r + 0][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c + 0]) != 15)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        /*
            a 3 x 3 magic square with distinct numbers from 1 to 9
            each row, column and both diagonals all have the same sum.
        */
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= m - 3; j++)
            {
                if (isMagicGrid(grid, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};