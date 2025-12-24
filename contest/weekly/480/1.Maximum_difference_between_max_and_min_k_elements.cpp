#include<bits/stdc++.h>
using namespace std;
// we are given an integer array and an integer k, we are supposed to find the maximum difference between the maximum k elements and minimum k elements in the array
class Solution{
    public:
    int absDifference(vector<int>& nums, int k){
        int n = nums.size();
        if(k > n) return 0; // difference is 0
        if (k == 0) return 0;

        sort(nums.begin(), nums.end());
        int maxSum = 0;
        int minSum = 0;
        for(int i = 0; i < k ; i++){
            maxSum += nums[n - i - 1];
            minSum += nums[i];
        }
        return abs(maxSum - minSum);
    }
};