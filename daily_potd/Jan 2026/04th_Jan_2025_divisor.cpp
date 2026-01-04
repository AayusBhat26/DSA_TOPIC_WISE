#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int helper(int num)
    {
        int count = 0;
        int sum = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                int divi1 = i;
                int divi2 = num / i;

                if (divi1 != divi2)
                {
                    count += 2;
                    sum += divi1 + divi2;
                }
                else
                {
                    count += 1;
                    sum += divi1; // both the divisiors are same therefore add only one of them
                }
                if (count > 4)
                    return 0;
            }
        }
        return (count == 4) ? sum : 0;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (helper(nums[i]))
            {
                sum += helper(nums[i]);
            }
        }
        return sum;
    }
};
