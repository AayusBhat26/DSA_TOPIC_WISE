#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        // rows x cols
        int n = matrix.size();

        long long totalSum = 0; // absolute sum

        long long count = 0; // count of negative elements in the matrix

        int minimumNumber = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // get the minimum element, we are making sure that we are dealing with positive numbers only
                minimumNumber = min(minimumNumber, abs(matrix[i][j]));

                // if the current element is negative increment the count of negative numbers
                if (matrix[i][j] < 0)
                    count++;

                totalSum += abs(matrix[i][j]); // we are finding the absolute sum, in the end we would subtract the required thing
            }
        }

        // if the count of negative elements is even, then this means that we can select those two elements and multiply them by -1, so eventually making them positive
        if (count % 2 == 0)
        {

            return totalSum;
        }

        // number of negative elements turns out of odd so we will subtract the minimum number out of all

        return (totalSum - 2 * minimumNumber);
    }
};